#ifndef FicheroLista
	#include "Lista.h"
	#define FicheroLista
#endif

#define FicheroHashtable
#define TAMHASH 101
typedef struct Diccionario Diccionario;

struct Diccionario {
	struct Diccionario *next;
	char *clave;
	Lista valor;
};

//extern Diccionario *tablahash[TAMHASH];

unsigned hash(char *);
extern Diccionario *buscar_enhash(char *);
extern Diccionario *agregar_enhash(char *);
extern Diccionario *eliminar_enhash(char *);
