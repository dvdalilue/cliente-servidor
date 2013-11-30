#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

/// IMPLEMENTACION DE UNA COLA ///
/// CON SUS FUNCIONES BASICAS ///

void cola_inic (tipoCola **c) {
  *c = (tipoCola *) malloc (sizeof(tipoCola));
  (**c).primero = NULL;
  (**c).ultimo = NULL;
  (**c).cantidad = 0;
}

int estaVacio(tipoCola *c) {
    if((*c).cantidad == 0) {
        return 1;
    }
    return 0;
}

void cpstr (char * str1, char * str2) {
  int i = 0;
  while (str2[i] != '\0') {
    str1[i] = str2[i];
    i++;
  }
  str1[i] = str2[i];
}

void vaciarCaja (tipoCaja ** caja) {
  free((*(*caja)).elem);
  free((*(*caja)).arg);
  free((*caja));
}

void encolar (tipoCola* c, char* str, char* str2) {
  tipoCaja* aux = (tipoCaja*) malloc (sizeof(tipoCaja));
  (*aux).elem = (char *) malloc (sizeof(str));
  (*aux).arg = (char *) malloc (sizeof(str2));
  cpstr((*aux).elem, str);
  cpstr((*aux).arg, str2);
  (*aux).siguiente = NULL;

  if ((*c).cantidad == 0) {
    (*c).primero = aux; 
    (*c).ultimo = aux;
  } else {
    (*((*c).ultimo)).siguiente = aux;
    (*c).ultimo = aux;
  }
  c->cantidad++;
}

void desencolar (tipoCola* c, tipoCaja ** caja) {
  *caja = NULL;
  if ((*c).cantidad != 0) {
    *caja = (*c).primero;
    (*c).primero = (*(*caja)).siguiente;
    c->cantidad--;
  }
}
