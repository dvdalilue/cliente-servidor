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
  // Si alguno no fue especificado, termina la ejecucion con un mensaje
  if (puerto == 0) {
    printf("\n***Falta espesificar el puerto!!!***\n\n");
    exit(0);
  }

  //Declarcion del descriptor del socket y estructuras relevantes

  int sock_desc, sock_fd;
  socklen_t cliente;
  struct sockaddr_in dir_sever, dir_clien;
  char tmp[512];
  tipoCola *cola;
  tipoCaja *caja;

  //Creacion del socket

  if ((sock_desc = socket(AF_INET, SOCK_STREAM,0)) < 0) {
    perror("socket");
    return 1;
  }
  //bzero((char *) &dir_sever, sizeof(dir_sever));


  dir_sever.sin_family = AF_INET;
  dir_sever.sin_addr.s_addr = inet_addr("127.0.0.1");
  dir_sever.sin_port = htons(puerto);

  bzero(&(dir_sever.sin_zero),8);

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

  printf("Servidor Activo y Escuchando!!\n\n...");
  
  cliente = sizeof(dir_clien);
  cola_inic(&cola);  

  while (true) {

    //Acepta las peticiones si es que han llegado en un nuevo descriptor

    if ((sock_fd = accept(sock_desc, (struct sockaddr *) &dir_clien, &cliente)) == -1) {
      perror("accept");
      return 4;
    }

    bzero(tmp, sizeof(tmp));
    //Lee del descriptor sock_fd

    if (read(sock_fd,tmp,511) < 0) {
      perror("Error leyendo del socket");
      return 5;
    }
    extrat_cmd(tmp,cola);

    while(!estaVacio(cola)) {
      desencolar(cola,&caja);
      printf("palabras: %s***%s\n",(*caja).elem,(*caja).arg);
      vaciarCaja(&caja);
    }
    free(cola);
    //Envia un mensaje de respuesta

    if (send(sock_fd,"Mensaje recibido\n",17,0) < 0) {
      perror("Error escribiendo en el socket");
      return 6;
    }
  }
  close(sock_fd);
  close(sock_desc);
  return 0;
}
