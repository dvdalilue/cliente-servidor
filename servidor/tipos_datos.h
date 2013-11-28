/* Estructura que representa el conjunto de datos que envia un cliente al
 * servidor.
 */
typedef struct {
	char *nombre;
	int user_sockfd;
	char *mensaje;
	Lista salas;
	int tamListaSalas;
} CajaUsuario;
