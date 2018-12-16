#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/** Crea una cola */
Queue* queue_init()
{
  // Pido memoria para la cola
  Queue* queue = malloc(sizeof(Queue));

  // Creo la lista que usare y la agrego a la cola
  queue -> list = list_init();

  // Retorno la cola
  return queue;
}

/** Inserta un numero en la cola */
void queue_push(Queue* queue, int value)
{
  // Solo llamo a la funcion push_front de la lista
  list_push_front(queue -> list, value);
}

/** Elimina un numero de la cola y lo retorna */
int queue_pop(Queue* queue)
{
  // Solo llamo a la funcion pop_back de la lista
  return list_pop_back(queue -> list);
}

/** Libera los recursos de la cola */
void queue_destroy(Queue* queue)
{
  // Libero la lista
  list_destroy(queue -> list);

  // Libero la cola
  free(queue);
}
