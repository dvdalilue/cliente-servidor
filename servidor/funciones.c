#include <stdbool.h>
#include <stdio.h>
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

int cp_untilsp (char * arr1, char * arr2, int * ini) {
  
  int i = (*ini), j = 0;
  while ((32 != arr2[i]) && (arr2[i] != 10)) {
    arr1[j] = arr2[i];
    i++;
    j++;
  }
  (*ini) = i;
  return j;
}

void extrat_cmd(char * mensaje, tipoCola * cola) {

  char tmp[10];
  char arg[25];
  int i = 0, j;

  while (mensaje[i] != '\0') {
    j = cp_untilsp(tmp,mensaje,&i);
    tmp[j+1] = '\0';
    printf("*********%c\n",mensaje[i]);
    if (mensaje[i] == ' ') {
      i += cp_untilsp(arg,mensaje,&i);
    }
    //printf("palabraaaaaaa: %s\n",tmp);
    encolar(cola,tmp,arg);
    i++;
  }

}
