#ifndef hashtable
#define hashtable
#include "lista.c"

typedef struct _tipoDic {
  struct _tipoDic *next;
  char *clave;
  Lista valor;
} Diccionario;

/* Estructura que representa el conjunto de datos que envia un cliente al
 * servidor.
 */
typedef struct _tipoCajaUsuario {
  char *nombre;
  int user_sockfd;
  char *mensaje;
  Lista salas;
  int tamListaSalas;
} CajaUsuario;


//extern Diccionario *tablahash[TAMHASH];

unsigned hash(char *, Diccionario * tablahash[]);
Diccionario * buscar_enhash(char *, Diccionario * tablahash[]);
Diccionario * agregar_enhash(char *, Diccionario * tablahash[]);
Diccionario * eliminar_enhash(char *, Diccionario * tablahash[]);

#endif
