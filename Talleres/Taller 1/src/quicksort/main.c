#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char *argv[])
{
  // Compruebo que se llame correctamente al programa
  if (argc != 2)
  {
    printf("Modo de uso incorrecto. Debes dar el numero de datos a ordenar\n");
    return 0;
  }

  // Cantidad de numeros a ordenar
  int total = atoi(argv[1]);

  // Creo una lista
  LinkedList* ll = ll_init();

  // Agrego numeros aleatorios a la lista entre 0 y 10000
  for (int i = 0; i < total; i++)
  {
    // Numero aleatorio entre 0 y 1000
    ll_append(ll, rand() % 1000);
  }

  // Ordeno
  ll_quicksort(ll);

  // Imprimo lista
  // for (Node* node = ll -> head; node; node = node -> next)
  // {
  //   printf("%d\n", node -> value);
  // }

  // Libero
  ll_destroy(ll);

  return 0;
}
