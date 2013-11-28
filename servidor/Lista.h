/* Lista.h
 * Definiciones utilizadas en Lista.c
 *
 * @author: Michael Woo 09-10912
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FicheroLista

/* Representacion de una Caja de la lista.
 */
struct Caja {
	char *nombre;
	void *datos;
	struct Caja *next;
};

/* Definicion de lista para comodidad en el paso
 * de argumentos en funciones/procedimientos
 */
typedef struct Caja *Lista;
typedef struct Caja Caja;

struct CajaUsuario {
	char *nombre;
	int user_sockfd;
	char *mensaje;
	Lista salas;
	int tamListaSalas;
};

typedef struct CajaUsuario CajaUsuario;

/* Prototipos de funciones para Lista.c */
extern int buscar_enlista(Lista , Caja *);
extern Lista agregar_enlista(Lista , Caja * );
extern Lista eliminar_enlista(Lista , char * );
//Fin Lista.h
