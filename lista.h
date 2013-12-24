#ifndef lista
#define lista

/* Representacion de una Caja de la lista.
 */
typedef struct _Caja {
  char* nombre;
  int datos;
  struct _Caja *next;
} Caja;

/* Definicion de lista para comodidad en el paso
 * de argumentos en funciones/procedimientos
 */
typedef struct _Lista {
  struct _Caja *inicio;
} Lista;

/* Prototipos de funciones para Lista.c */
void iniciar_lista(Lista ** lista);
Caja * buscar_enlista(Lista * l, char * n);
void agregar_enlista(Lista * l, char * d, int v);
void eliminar_enlista(Lista * l, char * e);
char * to_s(Lista * l);

#endif
//Fin lista.h
