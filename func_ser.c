#include "func_ser.h"

//// Funcion que verifica si un archivo existe /////
//// en el directorio, retornando true en acierto /////
//// false en caso de fallo /////

bool file_exists(char * filename) {

  FILE * file;
  if (file = fopen(filename, "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

int cp_untilsp (char * arr1, char * arr2, int * ini) {
  
  int i = (*ini), j = 0;
  while ((32 != arr2[i]) && (arr2[i] != 10) && (arr2[i] != 0)) {
    arr1[j] = arr2[i];
    i++;
    j++;
  }
  (*ini) = i;
  return j;
}

void rmspc (char * str, int * i) {
  int j = *i;
  while (str[j] == ' ') {
    j++;
  }
  *i = j;
}

void extrat_cmd(char * mensaje, tipoCola * cola) {

  char tmp[10];
  char arg[25];
  int i = 0, j;

  while (mensaje[i] != '\0') {
    rmspc(mensaje,&i);
    j = cp_untilsp(tmp,mensaje,&i);
    tmp[j] = '\0';
    if (mensaje[i] == ' ') {
      rmspc(mensaje,&i);
      j = cp_untilsp(arg,mensaje,&i);
      arg[j] = '\0';
    } else {
      arg[0] = '\0';
    }
    encolar(cola,tmp,arg);
    i++;
  }
}

// La funcion de agregar Sala puede ser reemplazada por la de agregar_enhash

// La funcion de eliminar Sala puede ser reemplazada por la de eliminar_enhash

// Funcion para suscribir un usuario a una sala de chat

// void? Podria devolver 0 en caso de haberse suscrito con exito y otro valor
// dependeindo de la situacion que haya podido ocurrir (excepciones).
/* void agregarUsuario(char *sala, void *user) { */
/* 	// Estructura que describe a un usuario suscrito a una sala de chat */
/* 	/\* Esta estructura contiene: */
/* 	 * - nombre (char *): Nombre del usuario. */
/* 	 * - datos (int): File descriptor del socket por el que se conecto el usuario */
/* 	 *\/ */
/* 	Caja *u; */
/* 	CajaUsuario *info_u; */
/* 	Diccionario *s; */

/* 	info_u = (CajaUsuario *)user; */
/* 	// Creacion de estructura que sera agregada en la lista. */
/* 	u = (Caja *)malloc(sizeof(Caja)); */
/* 	u->nombre = info_u->nombre; */
/* 	u->datos = (void *)info_u->user_sockfd; */

/* 	if((s = buscar_enhash(sala)) == NULL) */
/* 		//AQUI VA UN MANEJO DE ERORRES PARA EL QUE ABAJO SE DESCRIBE */
/* 		printf("No se puede encontrar la sala %s",sala); */

/* 	agregar_enlista(s->valor, u); */
/* 	agregar_enlista(usuarios, u); */

/* } */

/* // Funcion para desuscribir a un usuario de las salas en las que se encuentra */
/* // suscrito */
/* void eliminarUsuario(void *user) { */

/*   CajaUsuario *info_u; */
/*   Diccionario *s; */
/*   Lista salas; */
  
/*   info_u = (CajaUsuario *)user; */
/*   for(salas=info_u->salas; salas!=NULL; salas=salas->next) */
/*     // Se crean procesos hijos que se encarguen de la desuscripcion */
/*     if(fork() == 0) { */
/*       if((s = buscar_enhash(salas->nombre)) == NULL) */
/*         printf("Error al buscar la sala %s.",salas->nombre); */
/*       // Se obtiene la informacion de la sala de chat */
/*       eliminar_enlista(s->valor, info_u->nombre); */
/*     } */

/*   // Se eliminan las salas a las queinclude in c el usuario estaba suscrito */
/*   info_u->salas = NULL; */
/* } */

/* // Procedimiento que muestra en pantalla la lista de salas de chat en el */
/* // servidor */
/* void listarSalas() { */
/*   int i; */
/*   Diccionario *sala; */

/*   for(i=0; i<TAMHASH; i++) */
/*     if(tablahash[i]!=NULL && fork()==0) { */
/*       for(sala=tablahash[i]; sala!=NULL; sala=sala->next) */
/*         printf("%s\n",sala->clave); */
/*       exit(0); */
/*     } */
/* } */

/* // Procedimiento que muestra en pantalla la lista de usuarios conectados al */
/* // servidor */
/* void listarUsuarios() { */
/*   Lista u; */
/*   for(u=usuarios; u!=NULL; u=u->next) */
/*     printf("%s\n",u->nombre); */
/* } */


void manejador_cmd (tipoCaja * caja, char * tmp) {
  
  if (strcmp((*caja).elem,"sal") == 0) {
    //kill(getppid(),);
  }
  else if (strcmp((*caja).elem,"usu") == 0) {
    kill(getppid(),17);
  }
  else if (strcmp((*caja).elem,"men") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"sus") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"des") == 0) {
    printf("Comando: %s\n",(*caja).elem);
  }
  else if (strcmp((*caja).elem,"cre") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);
  }
  else if (strcmp((*caja).elem,"eli") == 0) {
    printf("Comando: %s***Argumento: %s\n",(*caja).elem, (*caja).arg);  
  }
  else if (strcmp((*caja).elem,"fue") == 0) {
    strcpy(tmp, "fue\0");
  } else {
    printf("Comando invalido\n");
  }
}

/* void crearVoid(tipoArgsHilo **aux, char *dir, int nivel, char *salida, int *dirs, int *archs) { */
/*   *aux = (tipoArgsHilo *) malloc (sizeof(tipoArgsHilo)); */
/*   (**aux).dir = dir; */
/*   (**aux).nivel = nivel; */
/*   (**aux).salida = salida; */
/*   (**aux).numDirs = dirs; */
/*   (**aux).numArchs = archs; */
/* } */
