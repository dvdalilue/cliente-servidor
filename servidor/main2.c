#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "funciones.c"
#include "../estructuras/Hashtable.h"
#include "../estructuras/Lista.h"
#include "../estructuras/tipos_datos.h"

int main(int argc, char *argv[]) {
	char *nombre;

	nombre=getChar();
	agregarSala(nombre);
}
