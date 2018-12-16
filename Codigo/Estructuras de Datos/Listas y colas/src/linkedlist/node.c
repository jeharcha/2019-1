#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/** Crea un nodo con el entero que guarda */
Node* node_inint(int value)
{
  // Pido la memoria al sistema operativo para poder almacenar mi nodo
  Node* node = malloc(sizeof(Node));

  // Agrego el valor al nodo
  node -> value = value;

  // Inicializo sus punteros como nulos
  node -> last = NULL;
  node -> next = NULL;

  // Retorno el nodo creado
  return node;
}

/** Libera la memoria del nodo */
void  node_destroy(Node* node)
{
  // Libero la memoria que pedi al crear el nodo
  free(node);
}
