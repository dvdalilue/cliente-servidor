#include <stdio.h>
#include <stdbool.h>
#include "funciones.h"

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

//// Funcion que lee un archivo completo y lo coloca todo /////
//// en un string

void read_file(char * mensaje, char * filename) {

  if (file_exists(filename)) {
    FILE * file;
    char aux[50];
    file = fopen(filename,"r");
    while (fgets(aux,50,file) != NULL) {
      strcat(mensaje,aux);
    }
  } else {
    printf("***El archivo no existe\n");
  }
}

char *extrat_cmd(char *mensaje) {
	char[3] cmd;
	int i;

	for(i=0;i<3;i++)
		cmd[i] = mensaje[i]

	return cmd;
}

//Crear la caja de envio
CajaUsuario *crearUsuario(char *nombre, int sockfd) {
	CajaUsuario *usuario;

	usuario = (CajaUsuario *)malloc(sizeof(CajaUsuario));
	usaurio->nombre = nombre;
	usuario->user_sockfd = sockfd;

	return usuario;
}


void mostrarAyuda() {
	printf("\nLos comandos disponibles son:\n
					\tsal : Mostrar por pantalla las salas disponibles en el servidor.\n
					\tsus <sala> : Suscribirse a la sala de chat <sala>.\n
					\tdes : Desusbrirse de las salas de chat a las que esta suscrito.\n
					\tcre <sala> : Crear la sala de chat <sala> en el servidor.\n
					\teli <sala> : Eliminar la sala de chat <sala> en el servidor.\n
					\tusu : Mostrar por pantalla los usuarios suscritos al servidor.\n
					\tmen <mensaje> : Envia <mensaje> a los usuarios suscritos a las salas de chat a las que se encuentra suscrito.\n
					\tfue : Termina la ejecucion del programa cchat.\n
					\tayu : Mostrar por pantalla esta ayuda.\n\n")
}

//Enviar la caja al servidor
void enviarPaquete(char *mensaje, void *info_u) {
	CajaUsuario *envio;
	int sockfd_servidor;

	envio = (CajaUsuario *)info_u;
	sockfd_servidor = envio->user_sockfd

	if(strcmp(extrat_cmd(mensaje),"ayu") == 0)
		mostrarAyuda();
	else {
		envio = (CajaUsuario *)info_u;
		envio->mensaje = mensaje;
	}
	//Enviando la caja al servidor
	send(sockfd_servidor, &envio, sizeof(CajaUsuario), 0)
}

//Recibir e interpretar la caja de respuesta de solicitud
void recibePaquete(void *info_u) {
	CajaUsuario *usuario;
	CajaServidor *servidor;
	int sockfd_servidor;

	usuario = (CajaUsuario *)info_u;
	sockfd_servidor = usuario->user_sockfd;
	//Recibiendo la respuesta del servidor
	recv(sockfd_servidor, &servidor, sizeof(CajaServidor), 0)
	
	/*En esta parte se debe interpretar el mensaje que mando el servidor
	 *y dependiendo de lo que este diga se debe ejecutar las acciones
	 *correspondientes (interpretar los comandos del lado del cliente).
	 */
}
