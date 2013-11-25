#include <stdio.h>
#include <stdbool.h>
#include "funciones.h"

//// Funcion que verifica si un archivo existe /////
//// en el directorio, retornando true en acierto /////
//// false en caso de fallo /////

bool file_exists(char * filename) {

  FILE * file;
  if (file = fopen(filename, "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

//// Funcion que lee un archivo completo y lo coloca todo /////
//// en un string

void read_file(char * mensaje, char * filename) {

  if (file_exists(filename)) {
    FILE * file;
    char aux[50];
    file = fopen(filename,"r");
    while (fgets(aux,50,file) != NULL) {
      strcat(mensaje,aux);
    }
  } else {
    printf("***El archivo no existe\n");
  }
}
