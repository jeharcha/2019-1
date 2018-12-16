#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/** Crea una stack */
Stack* stack_init()
{
  // Pido memoria paral stack
  Stack* stack = malloc(sizeof(Stack));

  // Creo la lista que usare y la agrego al stack
  stack -> list = list_init();

  // Retorno el stack
  return stack;
}

/** Inserta un numero en el stack */
void stack_push(Stack* stack, int value)
{
  // Solo llamo a la funcion push_back de la lista
  list_push_back(stack -> list, value);
}

/** Elimina un numero de el stack y lo retorna */
int stack_pop(Stack* stack)
{
  // Solo llamo a la funcion pop_back de la lista
  return list_pop_back(stack -> list);
}

/** Libera los recursos de el stack */
void stack_destroy(Stack* stack)
{
  // Libero la lista
  list_destroy(stack -> list);

  // Libero el stack
  free(stack);
}
