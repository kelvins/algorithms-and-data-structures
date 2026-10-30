/*
 *	Example of Sorted Sequential List implementation in C - Using
 *sentinel
 */

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int TIPOCHAVE; // Define TIPOCHAVE as an alias for an integer type

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX + 1]; // The extra position is used for the sentinel
  int nroElementos;
} LISTA;

void inicializar(LISTA *L) {
  L->nroElementos = 0; // Access the list through its memory address
  int i = 0;
  for (i; i < MAX - 2; ++i) { // Fill all but two slots, leaving room for more
    L->A[i].chave = i * 2;
  }
  L->nroElementos = MAX - 2;
  // (*L).nroElementos = 0; // This accesses the list itself, not the
  // pointer
}

/* The sentinel's purpose is to add the key at the end of the list, ensuring
 * the key is always found, even if it is in the last position.
 * If it is the last element, the key was not present in the original list.
 * This removes the 'if' from the loop and avoids several comparisons.
 */
int buscaSentinela(TIPOCHAVE ch,
                   LISTA *L) { // Binary search could be used here and would be
                               // more appropriate.
  int i = 0;
  L->A[L->nroElementos].chave =
      ch; // Assign the searched key/value to the last position of array A
  while (L->A[i].chave != ch) // Scan array A for the searched key/value;
                              // otherwise this is the sentinel
    i++;
  if (i == L->nroElementos) // Reaching the end means the value was not found;
                            // return ERROR (-1)
    return ERRO;
  return i; // Otherwise, return the position of the value/key in the array
}

bool inserirOrdenado(REGISTRO reg, LISTA *L) {
  int i = 0;
  if (L->nroElementos >= MAX)
    return false;
  L->A[L->nroElementos].chave = reg.chave;
  while (L->A[i].chave < reg.chave)
    i++;
  int p = L->nroElementos - 1;
  while (p >= i) {
    L->A[p + 1] = L->A[p];
    p--;
  }
  L->A[i] = reg;
  L->nroElementos++;
  return true;
}

bool deletaValor(REGISTRO reg, LISTA *L) {
  int posicao = buscaSentinela(reg.chave, L);
  if (posicao >= 0) {
    for (posicao; posicao < L->nroElementos; posicao++) {
      L->A[posicao] = L->A[posicao + 1];
    }
    L->nroElementos--;
    return true;
  } else {
    return false;
  }
}

void mostraLista(LISTA *L) {
  int i = 0;
  for (i; i < L->nroElementos;
       ++i) { // Visit and display every value in the array
    printf("%d, ", L->A[i].chave);
  }
  printf("\n\n");
}

int main() {

  LISTA LISTA;
  inicializar(&LISTA);

  printf("Valor 10 encontrado na posição: %d\n\n", buscaSentinela(10, &LISTA));
  mostraLista(&LISTA);

  REGISTRO reg;
  reg.chave = 7;
  printf("Insere o valor: %d\n", reg.chave);
  inserirOrdenado(reg, &LISTA);
  mostraLista(&LISTA);

  reg.chave = 12;
  printf("Deleta o valor: %d\n", reg.chave);
  deletaValor(reg, &LISTA);
  mostraLista(&LISTA);

  return 0;
}