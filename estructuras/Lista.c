/* Lista.c
 * Implementacion de una Lista simple enlazada de tipo generico.
 *
 * @author: Michael Woo 09-10912
 */

#include"Lista.h"

/* Agrega un elemento a la lista.
 * param:
 * l : Lista a agregar el elemento.
 * element : Elemento a agregar.
 * return : La lista con el elemento agregado.
 */
Lista agregar_enlista(Lista l, Data *d) {	
	/*Caso lista vacia*/
	if(l == NULL) {
		l->primero = d;
		l->ultimo = d;
	}
	/*Caso lista no vacia*/
	else {
		l->ultimo->next = d;
		l->ultimo = d;	
	}

	return l;
}

/* Elimina la primera ocurrencia de un elemento en la
 * lista en caso de estar, manteniendo el orden ascendente establecido.
 * param:
 * l : Lista en la cual se eliminara o no el elemento
 * element : Elemento a eliminar
 * return : La lista l con el elemento eliminado en dado caso, manteniendo
 *			el orden ascendente establecido
 */
Lista eliminar_enlista(Lista l, char *e) {
	Lista temp1, temp2;

	/*Caso lista vacia*/
	if(l == NULL)
		return NULL;
	/*Se verifica si el primer elemento coincide con el elemento a eliminar*/
	if(!strcmp(l->nombre,e)) {
		temp1 = l;
		l = l->next;
		free(temp1);
		return l;
	}
	/*Caso en que el elemento a eliminar no se encuentra en la primera posicion*/
	else {
		temp2 = l;
		temp1 = l->next;
		/*Se busca la primera ocurrencia del elemento y se elimina*/
		while(temp1 != NULL && strcmp(temp1->nombre,e)) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if(temp1 == NULL)
			return l;
		else {
			temp2->next = temp1->next;
			free(temp1);
			return l;
		}
	}
}
//Fin Lista.c
