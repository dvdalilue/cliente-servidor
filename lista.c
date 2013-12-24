#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void iniciar_lista(Lista ** l) {
  *l = (Lista *) malloc (sizeof(Lista));
  (**l).inicio = NULL;
}

/* Busca un elemento en la lista
 * param:
 * l : Lista en la que se realizara la busqueda
 * d : Elemento a buscar
 * return : 1 en caso de encontrar el elemento, 0 en caso contrario.
 */
Caja * buscar_enlista(Lista * l, char * n) {

  Caja *aux;
  aux = (*l).inicio;
  while (aux != NULL) {
    if (strcmp(aux->nombre,n) == 0) {
      return aux;
    }
    aux = aux->next;
  }
  return NULL;
}

/* Agrega un elemento a la lista.
 * param:
 * l : Lista a agregar el elemento.
 * element : Elemento a agregar.
 * return : La lista con el elemento agregado.
 */
void agregar_enlista(Lista * l, char * d, int v) {

  Caja *temp;
  temp = (Caja *)malloc(sizeof(Caja));
  temp->nombre = d;
  temp->datos = v;
  if(buscar_enlista(l,d) == NULL) {
    temp->next = l->inicio;
    l->inicio = temp;
  } else {
    free(temp);
  }
}

/* Elimina la primera ocurrencia de un elemento en la
 * lista en caso de estar, manteniendo el orden ascendente establecido.
 * param:
 * l : Lista en la cual se eliminara o no el elemento
 * element : Elemento a eliminar
 * return : La lista l con el elemento eliminado en dado caso, manteniendo
 *                        el orden ascendente establecido
 */
void eliminar_enlista(Lista * l, char * e) {

  Caja * temp;
  temp = buscar_enlista(l,e);

  if (temp != NULL) {
    if (l->inicio == temp) {
      l->inicio = temp->next;
      free(temp);
    } else {
      Caja * aux = l->inicio;
      while (aux->next != temp) {
        aux = aux->next;
      }
      aux->next = temp->next;
      free(temp);
    }
  }
}

char * to_s(Lista * l) {
  
  Caja * tmp;
  tmp = (*l).inicio;
  char * resp = (char *) malloc (512);
  while (tmp != NULL) {
    strcat(resp, tmp->nombre);
    strcat(resp,"\n");
    tmp = tmp->next;
  }
  return resp;
}

//Fin Lista.c
