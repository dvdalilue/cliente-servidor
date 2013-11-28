#include <stdbool.h>
<<<<<<< HEAD:funciones.h
#include "queue.c"
#ifndef FicheroHashtable
	#include "Hashtable.h"
	#define FicheroHashtable
=======
#include "Hashtable.c"
#include "queue.c"
#ifndef FicheroHashtable
#define FicheroHashtable
>>>>>>> 97e4f04... Cambios a las estructuras, un poco, para otros casos:servidor/funciones.h
#endif

bool file_exists(char * filename);
int cp_untilsp (char * arr1, char * arr2, int * ini);
void rmspc (char * str, int * i);
void extrat_cmd(char * mensaje, tipoCola * cola);
void agregarUsuario(char *, void *);
void eliminarUsuario(void *user);
void listarSalas();
void listarUsuarios();
void manejador_cmd (tipoCaja * caja); 
