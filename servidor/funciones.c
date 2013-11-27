#include <stdbool.h>
#include <stdio.h>
#include "funciones.h"

extern tablahash;
extern usuarios;

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
  while ((32 != arr2[i]) && (arr2[i] != 10)) {
    arr1[j] = arr2[i];
    i++;
    j++;
  }
  (*ini) = i;
  return j;
}

void extrat_cmd(char * mensaje, tipoCola * cola) {

  char tmp[10];
  char arg[25];
  int i = 0, j;

  while (mensaje[i] != '\0') {
    j = cp_untilsp(tmp,mensaje,&i);
    tmp[j+1] = '\0';
    printf("*********%c\n",mensaje[i]);
    if (mensaje[i] == ' ') {
      i += cp_untilsp(arg,mensaje,&i);
    }
    //printf("palabraaaaaaa: %s\n",tmp);
    encolar(cola,tmp,arg);
    i++;
  }

// La funcion de agregar Sala puede ser reemplazada por la de agregar_enhash

// La funcion de eliminar Sala puede ser reemplazada por la de eliminar_enhash

// Funcion para suscribir un usuario a una sala de chat

// void? Podria devolver 0 en caso de haberse suscrito con exito y otro valor
// dependeindo de la situacion que haya podido ocurrir (excepciones).
void agregarUsuario(char *sala, void *user) {
	// Estructura que describe a un usuario suscrito a una sala de chat
	/* Esta estructura contiene:
	 * - nombre (char *): Nombre del usuario.
	 * - datos (int): File descriptor del socket por el que se conecto el usuario
	 */
	Caja u;
	CajaUsuario info_u;
	Diccionario s;

	info_u = (CajaUsuario *)user
	// Creacion de estructura que sera agregada en la lista.
	u = malloc(sizeof(Caja));
	u->nombre = info_u->nombre;
	u->datos = (int)info_u->user_sockfd;

	if((s = buscar_enhash(sala)) == NULL)
		//AQUI VA UN MANEJO DE ERORRES PARA EL QUE ABAJO SE DESCRIBE
		printf("No se puede encontrar la sala %s",sala);

	agregar_enlista(s->valor, u);
	agregar_enlista(usuarios, u);

	// Se libera la memoria de la estructura agregada en las listas
	// (En el procedimiento de agregado en listas se realiza una copia de \'esta)
	free(u);
}

// Funcion para desuscribir a un usuario de las salas en las que se encuentra
// suscrito
void eliminarUsuario(void *user) {
	/* Estructura del algoritmo:
	 * 1- De la informacion que se obtenga del usuario, utilizar la lista de
	 *		salas a la que esta suscrito.
	 * 2- Crear una serie de procesos paralelos para que busquen en el
	 *		diccionario las salas en las que esta el usuario
	 * 3- Eliminar el usuario de las salas a las que pertenece
	 *
	 * PREGUNTA: Un usuario puede estar conectado al servidor y no estar
	 *					 suscrito a alguna sala?
	 */

	CajaUsuario info_u;
	Diccionario s;
	
	info_u = (CajaUsuario *)user;
	
	// Para cada sala en la que un usuario esta suscrito se busca se elimina
	// su suscripcion
	for(salas=info_u->salas; salas!=NULL; salas=salas->next)
		// Se crean procesos hijos que se encarguen de la desuscripcion
		if(fork() == 0) {
			if((s = buscar_enhash(salas->nombre)) == NULL)
				printf("Error al buscar la sala %s.",salas->nombre);
			// Se obtiene la informacion de la sala de chat
			eliminar_enlista(s->valor, info_u->nombre);
		}

	// Se eliminan las salas a las que el usuario estaba suscrito
	info_u->salas = NULL;
}

// Procedimiento que muestra en pantalla la lista de salas de chat en el
// servidor
void listarSalas() {
	for(i=0; i<TAMHASH; i++)
		if(tablahash[i]!=NULL && fork()==0)
			for(sala=tablahash[i]->valor; sala!=NULL; sala=sala->next)
				print("%s\n",sala->nombre);
}

// Procedimiento que muestra en pantalla la lista de usuarios conectados al
// servidor
void listarUsuarios() {
	for(u=usuarios; u!=NULL; u=u->next)
		printf("%s\n");
}
