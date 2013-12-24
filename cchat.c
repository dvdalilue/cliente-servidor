#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "func_cli.c"
#include "lista.c"

int main(int argc, char *argv[]) {

  int i = 1, puerto = -1;
  char *host = "127.0.0.1", *nombre = "vacio", *archivo = "vacio";
  
  while (i < argc) {
    if ((strcmp(argv[i],"-h") == 0) && (argv[i+1] != NULL)) {
      i++;
      host = argv[i];
    }
    else if ((strcmp(argv[i],"-p") == 0) && (argv[i+1] != NULL)) {
      i++;
      puerto = atoi(argv[i]);
    }
    else if ((strcmp(argv[i],"-n") == 0)  && (argv[i+1] != NULL)) {
      i++;
      nombre = argv[i];
    } 
    else if ((strcmp(argv[i],"-a") == 0) && (argv[i+1] != NULL)) {
      i++;
      archivo = argv[i];
    }
    i++;
  }

  if (puerto == -1 || strcmp(nombre,"vacio") == 0) {
    printf("\n***Falta espesificar puerto y/o nombre del cliente!!!\n\n");
    exit(0);
  }

  //Declaracion de variables
  int s, otro;
  struct sockaddr_in bs,des;
  char resp[255], men[512];
  int *sd, size;
  Lista * usu;

  // Creamos el socket
  if ((s = socket(AF_INET,SOCK_STREAM,0)) != -1) {
    //Asigna un nombre local al socket
    //Se prepara el nombre de la máquina remota
    des.sin_family = AF_INET;
    des.sin_addr.s_addr = inet_addr(host);
    des.sin_port = htons(puerto);

    //Establece la conexión con la máquina remota
    if ((connect(s,(struct sockaddr*)&des,sizeof(struct sockaddr))) == -1) {
      perror("connect");
      return 3;
    }
    //Envia el nombre antes que nada
    send(s,nombre,strlen(nombre),0);
    bzero(&men,sizeof(men));
    read_file(men,archivo);
    //Envía el mensaje
    send(s,men,511,0);

    //Recibe la respuesta
    read(s,resp, sizeof(resp));
    printf("<-Recibido: %s\n",resp);

    while (true) {
      bzero(&men,sizeof(men));
      printf("Introduzca el Comando~$ ");
      fgets(men, sizeof(men), stdin); // Pide por comando despues de leer o no el archivo
      if (send(s,men,511,0) < 0) {
        printf("error\n");
      }
      //Recibe la respuesta
      bzero(&resp,sizeof(resp));
      read(s,resp, sizeof(resp));
      if (strcmp(resp,"fue") == 0) { // Si se recibe fue, sale como se indico
        break;
      } else {
        wait(50);
        bzero(&men,sizeof(men)); // Caso para usu o nada
        read_file(men,resp);
        remove(resp);
        printf("<-Recibido:\n%s\n",men);
      }
    }
    //Se cierra la conexión (socket)
    close(s);
  } else {
    perror("socket");
    return 1;
  }
  return 0;
}
