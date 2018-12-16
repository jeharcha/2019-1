#pragma once

/** Estructura que maneja los nodos de una lista ligada */
typedef struct node
{
  /** Valor almacenado por el nodo */
  int value;
  /** Nodo anterior */
  struct node* last;
  /** Nodo siguiente */
  struct node* next;
} Node;

// Funciones publicas

/** Crea un nodo con el entero que guarda */
Node* node_inint(int value);

/** Libera la memoria del nodo */
void  node_destroy(Node* node);
