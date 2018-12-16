#pragma once

#include "list.h"

/** Estructura de una cola (encapsula a una lista ligada) */
typedef struct stack
{
  /** Lista ligda */
  List* list;
} Stack;

// Funciones privadas

/** Crea una cola */
Stack* stack_init();

/** Inserta un numero en la cola */
void stack_push(Stack* stack, int value);

/** Elimina un numero de la cola y lo retorna */
int stack_pop(Stack* stack);

/** Libera los recursos de la cola */
void stack_destroy(Stack* stack);
