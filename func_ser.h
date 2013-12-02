#include <stdbool.h>
#include "hashtable.c"
#include "queue.c"
#ifndef funciones
#define funciones

/* typedef struct _argsHilo {
  char *dir;
  int nivel;
  char *salida;
  bool b;
  int *numDirs;
  int *numArchs;
  } tipoArgsHilo;*/

bool file_exists(char * filename);
int cp_untilsp (char * arr1, char * arr2, int * ini);
void rmspc (char * str, int * i);
void extrat_cmd(char * mensaje, tipoCola * cola);
void agregarUsuario(char *, void *);
void eliminarUsuario(void *user);
void listarSalas();
void listarUsuarios();
void manejador_cmd (tipoCaja * caja, char * tmp);
//void crearVoid (tipoArgsHilo **aux, char *dir, int nivel, char *salida, int *dirs, int *archs);

#endif
