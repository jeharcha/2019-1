#include "queue.h"
#include "stack.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  // Creo una cola
  Queue* queue = queue_init();

  // Inserto muchos elementos
  for (int i = 0; i < 10; i++)
  {
    queue_push(queue, i);
  }

  // Elimino los elementos
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", queue_pop(queue));
  }

  // Libero la cola
  queue_destroy(queue);

  // Creo un stack
  Stack* stack = stack_init();

  // Inserto muchos elementos
  for (int i = 0; i < 10; i++)
  {
    stack_push(stack, i);
  }

  // Elimino los elementos
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", stack_pop(stack));
  }

  // Libero el stack
  stack_destroy(stack);

  // Retorno 0
  return 0;
}
