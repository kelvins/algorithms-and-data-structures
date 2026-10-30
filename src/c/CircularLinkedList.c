/*
 *
 *	Linked List with Head Node, Circular and Sorted (Dynamic Implementation)
 *
 */

#include <malloc.h>
#include <stdio.h>

typedef int TIPOCHAVE; // Key type for each list node

// Data structure representing each list node
typedef struct AUX {
  TIPOCHAVE chave;
  struct AUX *prox;
} NO, *PONT;

typedef struct {
  PONT cab; // Head node
} LISTA;

void inicializar(LISTA *L) {
  // The head node keeps the list from being empty and can also be used as a
  // sentinela
  L->cab = (PONT)malloc(sizeof(NO));
  L->cab->prox = L->cab; // Initially points to itself because the list is circular
}

// Since this method does not modify the list, it can receive a copy instead
// of a pointer to it
PONT buscaSequencial(TIPOCHAVE ch, LISTA L, PONT *ant) {
  *ant = L.cab; // Since this is a copy, use dot (.) instead of arrow (->);
                // ant stores the pointer to the matching node
  PONT pos = L.cab->prox;
  L.cab->chave = ch; // Store the value in the head node as a sentinel; it will
                     // be the last value compared
  while (pos->chave != ch) {
    *ant = pos;      // Store the pointer to the node
    pos = pos->prox; // Move to the next node
  }
  if (pos != L.cab) // If this is not the head node, the value was found
    return pos;     // Return the node
  else
    return NULL; // Otherwise, return NULL
}

bool excluir(TIPOCHAVE ch, LISTA *L) {
  PONT aux, ant;
  aux = buscaSequencial(ch, *L,
                        &ant); // Find the value to remove. ant is passed by
                               // address so the search function can update it
                               // to hold the previous node
  if (aux == NULL)
    return false;
  ant->prox = aux->prox;
  free(aux);
  return true;
}

void inserir(TIPOCHAVE ch, LISTA *L) {
  PONT ant = L->cab;       // ant stores a pointer to the previous node
  PONT pos = L->cab->prox; // pos stores a pointer to the current node

  while (pos->chave < ch && pos != L->cab) {
    ant = pos;       // Store the current node pointer; it becomes the previous node
    pos = pos->prox; // Move to the next node
  }
  // The correct position in ascending order has been found
  PONT novo_no = (PONT)malloc(sizeof(NO));
  novo_no->chave = ch;
  novo_no->prox = pos;
  ant->prox = novo_no;
}

PONT mostrarLista(LISTA L) {
  PONT pos = L.cab->prox; // pos receives the first element after the head node
  while (pos != L.cab) {  // If it is not the head node, the list is not empty
    printf("[ %d ]->", pos->chave); // Display the node value
    pos = pos->prox;                // Move to the next node
  }
  printf("\n");
}

int main() {

  LISTA lista;
  inicializar(&lista);

  inserir(4, &lista);
  inserir(6, &lista);
  inserir(2, &lista);
  inserir(3, &lista);
  inserir(1, &lista);
  inserir(5, &lista);

  mostrarLista(lista);

  excluir(2, &lista);
  excluir(4, &lista);
  excluir(6, &lista);

  mostrarLista(lista);

  // Example of searching the list
  PONT aux;
  int valor = 2;
  if (buscaSequencial(valor, lista, &aux) != NULL)
    printf("Valor %d encontrado.\n", valor);
  else
    printf("Valor %d não encontrado.\n", valor);

  return 0;
}
