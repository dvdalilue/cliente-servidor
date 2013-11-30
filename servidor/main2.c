#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "Lista.c"
#include "Hashtable.c"
#include "funciones.c"

int main(int argc, char *argv[]) {
	Lista l;
	Lista a;
	Caja *c;
	int x;

	l = NULL;
	c = (Caja *)malloc(sizeof(Caja));
	c->nombre = "Lilue";
	c->datos = NULL;
	l = agregar_enlista(l,c);
	x = buscar_enlista(l,c);
	printf("%d\n",x);
	for(a=l;a!=NULL;a=a->next)
		printf("%s\n",a->nombre);

	agregar_enhash("Hola");
	listarSalas();
	eliminar_enhash("Hola");
	if(buscar_enhash("Hola")!=NULL)
		printf("Esta");
	else
		printf("NoEsta");
}
