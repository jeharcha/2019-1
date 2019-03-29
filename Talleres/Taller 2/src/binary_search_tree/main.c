#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "../random/pcg_basic.h"

int main(int argc, char *argv[])
{
	// Seteamos una semilla para los numeros aleatorios
	pcg32_srandom(0x853c49e6748fea9bULL, 0xda3e39cb94b95bdbULL);

	// Creamos un árbol binario con una llave y un valor aleatorio.
	BST* tree = bst_init(pcg32_boundedrand(1000), pcg32_boundedrand(1000));

	// Agregamos 100 datos al azar
	for(int i = 0; i < 100; i++)
	{
		bst_insert(tree, pcg32_boundedrand(1000), pcg32_boundedrand(1000));
	}

	// Buscamos una llave e imprimimos key, value si la encontramos
	BST* result = bst_search(tree, 210, 0);
	if(result)
	{
		printf("%d, %d\n", result->key, result->value);
	}else{
		printf("No existe esa llave.");
	}

	// Imprimimos el arbol de izquierda a derecha
	bst_in_order(tree);

	// Eliminamos el árbol
	bst_destroy(tree);
	return 0;
}
