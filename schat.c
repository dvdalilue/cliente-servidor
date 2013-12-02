#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "func_ser.c"

Lista * usuarios;

void manejador_signal(int signo) {
  if (signo == 17) {
    Caja *apt;
    apt = (*usuarios).inicio;
    while (apt != NULL) {
      printf("%s\n",apt->nombre);
      apt = apt->next;
    }
  }
}

int main(int argc, char *argv[]) {

  sigaction(17,manejador_signal);

  //Reconocimiento de opciones de entrada

  int i = 1, puerto = 0;
  char *sala = "actual";
  
  while (i < argc) {
    //Reconoce el numero del puerto
    if ((strcmp(argv[i],"-p") == 0)  && (argv[i+1] != NULL)) {
      i++;
      puerto = atoi(argv[i]);
    }
    //Reconoce el nombre de la sala
    else if ((strcmp(argv[i],"-s") == 0) && (argv[i+1] != NULL)) {
      i++;
      sala = argv[i];
    }
    i++;
  }
  // Si el puerto no fue especificado, termina la ejecucion con un mensaje
  if (puerto == 0) {
    printf("\n***Falta espesificar el puerto!!!***\n\n");
    exit(0);
  }
  //Declarcion del descriptor del socket y estructuras relevantes
  int sock_desc, sock_fd;
  socklen_t cliente;
  struct sockaddr_in dir_sever, dir_clien;
  char tmp[512];
  char * nombre;
  tipoCola *cola;
  tipoCaja *caja;
  Caja * apt;
  pid_t hijo;

  //Creacion del socket
  if ((sock_desc = socket(AF_INET, SOCK_STREAM,0)) < 0) {
    perror("socket");
    return 1;
  }
  //Inicializacion de la estructura del servidor
  dir_sever.sin_family = AF_INET;
  dir_sever.sin_addr.s_addr = INADDR_ANY;
  dir_sever.sin_port = htons(puerto);

  //Enlaza el sock descriptor con la direccion del servidor
  if (bind(sock_desc, (struct sockaddr *) &dir_sever, sizeof(dir_sever)) < 0) {
    perror("bind");
    return 2;
  }

  //Escucha por peticiones
  if (listen(sock_desc,2) == -1) {
    perror("listen");
    return 3;
  }
  printf("Servidor Activo y Escuchando!!\n\n");
  
  cliente = sizeof(dir_clien);
  iniciar_lista(&usuarios);

  while (true) {

    //Acepta las peticiones si es que han llegado en un nuevo descriptor
    if ((sock_fd = accept(sock_desc, (struct sockaddr *) &dir_clien, &cliente)) == -1) {
      perror("accept");
      return 4;
    }

    bzero(tmp, sizeof(tmp));
    read(sock_fd,tmp,511);
    nombre = (char *) malloc (strlen(tmp));
    strcpy(nombre,tmp);
    hijo = fork();

    if (hijo == 0) {
      cola_inic(&cola);
      while (1) {
        bzero(tmp, sizeof(tmp));
        //Lee del descriptor sock_fd
        if (read(sock_fd,tmp,511) < 0) {
          perror("Error leyendo del socket");
          return 5;
        }
        if (tmp[0] != 0) {
          extrat_cmd(tmp,cola);
          bzero(tmp, sizeof(tmp));
          while(!estaVacio(cola)) {
            desencolar(cola,&caja);
            manejador_cmd(caja,tmp);
            vaciarCaja(&caja);
          }
          if (strcmp(tmp,"fue") == 0) {
            send(sock_fd,"fue\0",4,0);
          } else if (send(sock_fd,"Informacion recibida\n",21,0) < 0) {
            perror("Error escribiendo en el socket");
            return 6;
          }
        } else if (send(sock_fd,"No hubo ningun mensaje\n",23,0) < 0) {
          perror("Error escribiendo en el socket");
          return 6;
        }
      }
      free(cola);
      close(sock_fd);
      exit(0);
    } else {
      agregar_enlista(usuarios,nombre,hijo);
      close(sock_fd);
    }
  }
  close(sock_desc);
  return 0;
}
