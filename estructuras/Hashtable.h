#include "Lista.h"

#define TAMHASH 101

struct Diccionario {
	struct Diccionario *next;
	char *clave;
	Lista valor;
};

static struct Diccionario *tablahash[TAMHASH];

unsigned hash(char *);

struct Diccionario *buscar_enhash(char *);

struct Diccionario *agregar_enhash(char *);

struct Diccionario *eliminar_enhash(char *);
