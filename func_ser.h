#include <stdbool.h>
#include "hashtable.c"
#include "queue.c"
#ifndef funciones
#define funciones

bool file_exists(char * filename);
int cp_untilsp (char * arr1, char * arr2, int * ini);
void rmspc (char * str, int * i);
void extrat_cmd(char * mensaje, tipoCola * cola);
void agregarUsuario(char *, void *);
void eliminarUsuario(void *user);
void listarSalas();
void listarUsuarios();
void manejador_cmd (tipoCaja * caja, char * tmp);

#endif