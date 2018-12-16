#pragma once

#include "list.h"

/** Estructura de una cola (encapsula a una lista ligada) */
typedef struct queue
{
  /** Lista ligda */
  List* list;
} Queue;

// Funciones privadas

/** Crea una cola */
Queue* queue_init();

/** Inserta un numero en la cola */
void queue_push(Queue* queue, int value);

/** Elimina un numero de la cola y lo retorna */
int queue_pop(Queue* queue);

/** Libera los recursos de la cola */
void queue_destroy(Queue* queue);
