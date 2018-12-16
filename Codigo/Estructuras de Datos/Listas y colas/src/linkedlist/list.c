#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/** Crea una lista vacia */
List* list_init()
{
  // Pido memoria para mi lista
  List* list = malloc(sizeof(List));

  // Inicializo sus valores
  list -> count = 0;
  list -> start = NULL;
  list -> end = NULL;

  // Retorno la lista creada
  return list;
}

/** Agrega un valor al final de la lista */
void list_push_back(List* list, int value)
{
  // Creo el nodo que voy a insertar en la lista
  Node* node = node_inint(value);

  // Hago que el nodo apunte al ultimo elemento de la lista
  node -> last = list -> end;

  // Si hay elementos en la lista
  if (list -> count > 0)
  {
    // Hago que el ultimo elemento apunte al nodo
    list -> end -> next = node;
    list -> end = node;
  }
  // Si no hay elementos en la lista
  else
  {
    // Entonces el nodo nuevo ahora es el primero y el ultimo de la lista
    list -> end = node;
    list -> start = node;
  }

  // Sumo 1 al contador de la lista
  list -> count++;
}

/** Agrega un valor al inicio de la lista */
void list_push_front(List* list, int value)
{
  // Creo el nodo que voy a insertar en la lista
  Node* node = node_inint(value);

  // Hago que el nodo apunte al primer elemento de la lista
  node -> next = list -> start;

  // Si hay elementos en la lista
  if (list -> count > 0)
  {
    // Hago que el primer elemento apunte al nodo
    list -> start -> last = node;
    list -> start = node;
  }
  // Si no hay elementos en la lista
  else
  {
    // Entonces el nodo nuevo ahora es el primero y el ultimo de la lista
    list -> end = node;
    list -> start = node;
  }

  // Sumo 1 al contador de la lista
  list -> count++;
}

/** Elimina el ultimo valor de la lista y lo retorna */
int list_pop_back(List* list)
{
  // Si la lista esta vacia
  if (list -> count == 0)
  {
    // Imprimo un mensaje de error
    printf("Error: No se puede eliminar un elemento de una lista vacia\n");
    // Termino el programa con un codigo de error
    exit(1);
  }

  // Obtengo el nodo a eliminar
  Node* node = list -> end;


  // Si solo habia 1 nodo
  if (list -> count == 1)
  {
    // Ahora el primer y ultimo nodo de la lista es nulo
    list -> start = NULL;
    list -> end = NULL;
  }
  // Sino
  else
  {
    // Hago que el ultimo elemento de la lista sea el anterior al nodo que sacamos
    list -> end = node -> last;
    // El ultimo apunta a null
    list -> end -> next = NULL;
  }

  // Quito 1 al contador de la lista
  list -> count--;

  // Obtengo el valor del nodo
  int value = node -> value;

  // Libero la memoria del nodo
  node_destroy(node);

  // Retorno el valor
  return value;
}

/** Elimina el primer valor de la lista y lo retorna */
int list_pop_front(List* list)
{
  // Si la lista esta vacia
  if (list -> count == 0)
  {
    // Imprimo un mensaje de error
    printf("Error: No se puede eliminar un elemento de una lista vacia\n");
    // Termino el programa con un codigo de error
    exit(1);
  }

  // Obtengo el nodo a eliminar
  Node* node = list -> start;


  // Si solo habia 1 nodo
  if (list -> count == 1)
  {
    // Ahora el primer y ultimo nodo de la lista es nulo
    list -> start = NULL;
    list -> end = NULL;
  }
  // Sino
  else
  {
    // Hago que el primer elemento de la lista sea el siguiente al nodo que sacamos
    list -> start = node -> next;
    // El primero apunta a null
    list -> start -> last = NULL;
  }

  // Quito 1 al contador de la lista
  list -> count--;

  // Obtengo el valor del nodo
  int value = node -> value;

  // Libero la memoria del nodo
  node_destroy(node);

  // Retorno el valor
  return value;
}

/** Imprime los elementos de la lista */
void list_print(List* list)
{
  // Itero sobre los nodos de la lista encerrados en parentesis
  printf("( ");
  for (Node* node = list -> start; node; node = node -> next)
  {
    // Imprimo el nodo seguido de un espacio
    printf("%d ", node -> value);
  }
  printf(")\n");
}

/** Libera la memoria de la lista */
void list_destroy(List* list)
{
  // Primero libero la memoria de los nodos que quedan en la lista
  Node* actual = list -> start;
  Node* next;
  while (actual)
  {
    next = actual -> next;
    node_destroy(actual);
    actual = next;
  }

  // Luego libero la memoria de la lista
  free(list);
}
