#ifndef funciones
#define funciones
#include "queue.c"

bool file_exists(char * filename);
int cp_untilsp (char * arr1, char * arr2, int * ini);
void rmspc (char * str, int * i);
void extrat_cmd(char * mensaje, tipoCola * cola);
void eliminarUsuario(void *user);
void manejador_cmd (tipoCaja * caja);

#endif
