/*************************
 Clase que define una tabla de Hash a ser utilizada como lista de salas
 de chat. Las entradas del tipo (clave, valor) se traducen en:
 - clave: Nombre de la sala de chat.
 - valor: Lista de los usuarios que pertenecen a la sala.
**************************/

#include "Hashtable.h"
Diccionario *tablahash[TAMHASH];

/* hash:
 * Obtiene el codigo hash de una cadena de caracteres
 */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % TAMHASH;
}

/* lookup:
 * Revisa se una entrada se encuentra en el diccionario a partir de su
 * clave.
 */
Diccionario *buscar_enhash(char *s)
{
	struct Diccionario *np;
	for (np = tablahash[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->clave) == 0)
			return np; /* found */
	return NULL; /* not found */
}

/* agregar:
 * Agrega una dupla (clave, valor) al diccionario.
 */
Diccionario *agregar_enhash(char *clave)
{
	struct Diccionario *np;
	unsigned hashval;
	hashval = hash(clave);

	if ((np = buscar_enhash(clave)) == NULL) { /* not found */
		//Se crea la entrada del diccionario
		np = (struct Diccionario *) malloc(sizeof(*np));
		np->clave = clave;
		np->next = tablahash[hashval];
		tablahash[hashval] = np;
	} else { /* already there */
		np->next = tablahash[hashval];
		tablahash[hashval] = np;
	}
	return tablahash[hashval];
}

/* eliminar:
 * Elimina toda una entrada del diccionario a partir de una clave dada.
 */
Diccionario *eliminar_enhash(char *clave)
{
	struct Diccionario *temp, *np;
	unsigned hashval;

	if((np = buscar_enhash(clave)) != NULL) {
		temp = np;
		np = np->next;
		hashval = hash(clave);
		tablahash[hashval] = np;
		free(temp);
	}
	else
		return NULL;

	return np;
}
