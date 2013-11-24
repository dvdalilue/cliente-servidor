#include "Lista.h"

#define TAMHASH 101

struct Diccionario {
	struct Diccionario *next;
	char *clave;
	Lista valor;
};

static strcut Diccionario *tablahash[TAMHASH];

unsigned hash(char *);

struct Diccionario *buscar(char *);

struct Diccionario *agregar(char *, Data *);

struct Diccionario *eliminar(char *);
