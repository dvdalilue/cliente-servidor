#include "func_ser.h"

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
  while ((32 != arr2[i]) && (arr2[i] != 10) && (arr2[i] != 0)) {
    arr1[j] = arr2[i];
    i++;
    j++;
  }
  (*ini) = i;
  return j;
}

void rmspc (char * str, int * i) {
  int j = *i;
  while (str[j] == ' ') {
    j++;
  }
  *i = j;
}

void extrat_cmd(char * mensaje, tipoCola * cola) {

  char tmp[10];
  char arg[25];
  int i = 0, j;

  while (mensaje[i] != '\0') {
    rmspc(mensaje,&i);
    j = cp_untilsp(tmp,mensaje,&i);
    tmp[j] = '\0';
    if (mensaje[i] == ' ') {
      rmspc(mensaje,&i);
      j = cp_untilsp(arg,mensaje,&i);
      arg[j] = '\0';
    } else {
      arg[0] = '\0';
    }
    encolar(cola,tmp,arg);
    i++;
  }
}

void manejador_cmd (tipoCaja * caja, char * tmp) {
  
  if (strcmp((*caja).elem,"sal") == 0) {
    //kill(getppid(),);
  }
  else if (strcmp((*caja).elem,"usu") == 0) {
    strcpy(tmp, "usu\0");
    kill(getppid(),17);
  }
  else if (strcmp((*caja).elem,"men") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"sus") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"des") == 0) {
    printf("Comando: %s\n",(*caja).elem);
  }
  else if (strcmp((*caja).elem,"cre") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"eli") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);  
  }
  else if (strcmp((*caja).elem,"fue") == 0) {
    strcpy(tmp, "fue\0");
  } else {
    printf("Comando invalido\n");
  }
}
