#include <stdbool.h>
#include <stdio.h>
#include "funciones.h"

extern tablahash;

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

// Funcion para agregar una sala de chat
// Las salas de chat se manejaran por Tabla de Hash

// void? puede ser int para que devuelva 0 en caso que si agregue, 1 en caso
// contrario
void agregarSala(char *nombre) {
	// Estructura que describe la sala
	Caja s;

	s = malloc(sizeof(Caja));
	s->nombre = nombre;
	s->datos = NULL;

	agregar_enhash(nombre, e);
}

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
	u = malloc(sizeof(Caja));
	u->nombre = info_u->nombre;
	u->datos = (int)info_u->user_sockfd;

	if((s = buscar_enhash) == NULL)
		//AQUI VA UN MANEJO DE ERORRES PARA EL QUE ABAJO SE DESCRIBE
		printf("No se puede encontrar la sala %s",sala);

	agregar_enlista(s->valor, u);
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
}
