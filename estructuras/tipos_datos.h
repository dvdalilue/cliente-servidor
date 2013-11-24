#include "../Lista.h"

/* Estructura que representa el conjunto de datos que envia un cliente al
 * servidor.
 */
struct CajaUsuario {
	Lista salas;
	int tamListaSalas;
	char *mensaje;
}
