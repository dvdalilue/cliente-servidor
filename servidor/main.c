#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "funciones.c"

#define BACKLOG 2

int main(int argc, char *argv[]) {

  printf("PID: %d\n",getpid());

  //Reconocimiento de opciones de entrada

  int i = 1, puerto = 0;
  char *sala = "vacio";
  
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
  //Si alguno no fue especificado, termina la ejecucion con un mensaje
  /* if (puerto == 0 || strcmp(sala,"vacio") == 0) { */
  /*   printf("\n***Falta espesificar algun valor o no se hizo correctamente!!!\n\n"); */
  /*   exit(0); */
  /* } */

  //Declarcion del descriptor del socket y estructuras relevantes

  int sock_desc, sock_fd;
  socklen_t cliente;
  struct sockaddr_in dir_sever, dir_clien;
  char tmp[512];

  //Creacion del socket

  if ((sock_desc = socket(AF_LOCAL, SOCK_STREAM,0)) < 0) {
    perror("socket");
    return 1;
  }
  //bzero((char *) &dir_sever, sizeof(dir_sever));


  dir_sever.sin_family = AF_LOCAL;
  dir_sever.sin_addr.s_addr = inet_addr("127.0.0.1");//Debe ser cambiado por SALA de alguna forma
  dir_sever.sin_port = htons(puerto);

  //bzero(&(dir_sever.sin_zero),8);

  //Enlaza el sock descriptor con la direccion del servidor

  if (bind(sock_desc, (struct sockaddr *) &dir_sever, sizeof(dir_sever)) < 0) {
    perror("bind");
    return 2;
  }

  //Escucha por peticiones

  if (listen(sock_desc,BACKLOG) == -1) {
    perror("listen");
    return 3;
  }
  
  cliente = sizeof(dir_clien);

  //Acepta las peticiones si es que han llegado en un nuevo descriptor

  if (sock_fd = accept(sock_desc, (struct sockaddr *) &dir_clien, &cliente) != -1)
    error("Error al aceptar");

  //Inicializa el buffer "tmp" es zeros

  bzero(tmp, sizeof(tmp));

  //Lee del descriptor sock_fd

  if (read(sock_fd,tmp,511) < 0)
    error("Error leyendo del socket");

  printf("Mensaje: %s\n",tmp);

  //Envia un mensaje de respuesta

  if (write(sock_fd,"Mensaje recibido",16) < 0)
    error("Error escribiendo en el socket");

  printf("Se conectaron desde %s\n", inet_ntoa(dir_clien.sin_addr));
  send(sock_fd, "Bienvenido a mi servidor!!!\n",26, 0);
  close(sock_fd);
  close(sock_desc);
  return 0;
}
