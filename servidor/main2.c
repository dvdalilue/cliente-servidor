#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
	Lista l;
	Caja *c;
	l = NULL;
	c = (Caja *)malloc(sizeof(Caja));
	c->nombre = "Lilue";
	c->datos = NULL;
	agregar_enlista(l,c);
}
