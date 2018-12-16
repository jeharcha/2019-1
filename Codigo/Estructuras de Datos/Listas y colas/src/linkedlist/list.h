#pragma once

#include "node.h"

typedef struct list
{
  Node* start;
  Node* end;
  int count;
} List;

// Funciones publicas

/** Crea una lista vacia */
List* list_init();

/** Agrega un valor al final de la lista */
void list_push_back(List* list, int value);

/** Agrega un valor al inicio de la lista */
void list_push_front(List* list, int value);

/** Elimina el ultimo valor de la lista y lo retorna */
int list_pop_back(List* list);

/** Elimina el primer valor de la lista y lo retorna */
int list_pop_front(List* list);

/** Imprime los elementos de la lista */
void list_print(List* list);

/** Libera la memoria de la lista */
void list_destroy(List* list);
