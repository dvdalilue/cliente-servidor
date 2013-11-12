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
  char *host = "vacio", nombre = "vacio", archivo = "vacio";
  
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

  if (puerto == -1 || strcmp(host,"vacio") == 0 || strcmp(nombre,"vacio") == 0 || strcmp(archivo,"vacio") == 0) {
    printf("\n***Falta espesificar algun valor o no se hizo correctamente!!!\n\n");
    exit(0);
  }

  return 0;
}
