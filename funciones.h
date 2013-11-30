#ifndef funciones
#define funciones

#include <stdbool.h>
#include "queue.c"
#ifndef FicheroHashtable
	#include "Hashtable.h"
	#define FicheroHashtable
#endif

bool file_exists(char * filename);
int cp_untilsp (char * arr1, char * arr2, int * ini);
void rmspc (char * str, int * i);
void extrat_cmd(char * mensaje, tipoCola * cola);
void agregarUsuario(char *, void *);
void eliminarUsuario(void *user);
void manejador_cmd (tipoCaja * caja, char * tmp);
void listarSalas();
void listarUsuarios();
void manejador_cmd (tipoCaja * caja, char * tmp);

#endif
