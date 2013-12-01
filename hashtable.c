/*************************
 Clase que define una tabla de Hash a ser utilizada como lista de salas
 de chat. Las entradas del tipo (clave, valor) se traducen en:
 - clave: Nombre de la sala de chat.
 - valor: Lista de los usuarios que pertenecen a la sala.
**************************/

#include "hashtable.h"

/* hash:
 * Obtiene el codigo hash de una cadena de caracteres
 */
unsigned hash(char *s, Diccionario * tablahash[])
{
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % sizeof(tablahash);
}

/* lookup:
 * Revisa se una entrada se encuentra en el diccionario a partir de su
 * clave.
 */
Diccionario * buscar_enhash(char *s, Diccionario * tablahash[])
{
  Diccionario *np;
  for (np = tablahash[hash(s, tablahash)]; np != NULL; np = np->next)
    if (strcmp(s, np->clave) == 0)
      return np; /* found */
  return NULL; /* not found */
}

/* agregar:
 * Agrega una dupla (clave, valor) al diccionario.
 */
Diccionario * agregar_enhash(char *clave, Diccionario * tablahash[])
{
  Diccionario *np;
  unsigned hashval;
  hashval = hash(clave, tablahash);

  if ((np = buscar_enhash(clave, tablahash)) == NULL) { /* not found */
    //Se crea la entrada del diccionario
    np = (Diccionario *) malloc(sizeof(*np));
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
Diccionario * eliminar_enhash(char *clave, Diccionario * tablahash[])
{
  
  Diccionario *temp, *np;
  unsigned hashval;

  if((np = buscar_enhash(clave, tablahash)) != NULL) {
    temp = np;
    np = np->next;
    hashval = hash(clave, tablahash);
    tablahash[hashval] = np;
    free(temp);
  }
  else
    return NULL;

  return np;
}
