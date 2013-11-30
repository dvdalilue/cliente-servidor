#ifndef queue
#define queue

/// Declaracion de los tipos necesarios ///
/// para la creacion de una cola ///

typedef struct _caja {
  char* elem;
  char* arg;
  struct _caja *siguiente;
} tipoCaja;

typedef struct _cola {
  struct _caja *primero;
  struct _caja *ultimo;
  int cantidad;
} tipoCola;

void cola_inic (tipoCola** c);
int estaVacio (tipoCola* c);
void cpstr (char * str1, char * str2);
void vaciarCaja (tipoCaja ** caja);
void encolar (tipoCola* c, char* str, char * str2);
void desencolar (tipoCola* c, tipoCaja ** caja);

#endif
