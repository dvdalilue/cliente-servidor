#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "funciones.c"

int main(int argc, char *argv[]) {

  int i = 1, puerto = -1;
  char *host = "vacio", *nombre = "vacio", *archivo = "vacio";
  
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

  /* if (puerto == -1 || strcmp(host,"vacio") == 0 || strcmp(nombre,"vacio") == 0 || strcmp(archivo,"vacio") == 0) { */
  /*   printf("\n***Falta espesificar algun valor o no se hizo correctamente!!!\n\n"); */
  /*   exit(0); */
  /* } */

  int s, otro;
  struct sockaddr_in bs,des;
  char resp[255];
  int *sd;

  // Creamos el socket
  if ((s = socket(AF_INET,SOCK_STREAM,0)) != -1) {

    /* bs.sin_family = AF_LOCAL; */
    /* bs.sin_port = htons(puerto); //Asigna un puerto disponible dela máquina */
    /* bs.sin_addr.s_addr = (((((127 << 8) | 0) << 8) | 0) << 8) | 1; //Asigna una IP de la máquina */

    //printf("%d*****%d\n",gethostbyname(host),inet_addr("127.0.0.1"));

    //Asigna un nombre local al socket
    //if ((bind(s,(struct sockaddr*)&bs, sizeof(struct sockaddr))) != -1) {
      //Se prepara el nombre de la máquina remota
      des.sin_family = AF_INET;
      des.sin_addr.s_addr = inet_addr("127.0.0.1");
      des.sin_port = htons(puerto);

      //Establece la conexión con la máquina remota
      if ((connect(s,(struct sockaddr*)&des,sizeof(struct sockaddr))) == -1) {
        perror("connect");
        return 3;
      }

      //Envía el mensaje
      send(s,"hola-soy cliente",17,0);
      //Recibe la respuesta
      recv(s,resp, sizeof(resp) ,0);
      printf("<-Recibido: %sn",resp);
      //Se cierra la conexión (socket)
      close(s);
      // } else {
      //   perror("socket");
      //   return 1;
  }
  return 0;
}
