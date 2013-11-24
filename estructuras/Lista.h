/* Lista.h
 * Definiciones utilizadas en Lista.c
 *
 * @author: Michael Woo 09-10912
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Representacion de una Caja de la lista.
 */
struct Caja {
	char *nombre;
	void *datos;
	struct Caja *next;
};

struct Lista {
	Caja *primero;
	Caja *ultimo;
};

/* Definicion de lista para comodidad en el paso
 * de argumentos en funciones/procedimientos
 */
typedef struct Caja Data;

/* Prototipos de funciones para Lista.c */
extern Lista agregar(Lista , Data * );
extern Lista eliminar(Lista , char * );
//Fin Lista.h
