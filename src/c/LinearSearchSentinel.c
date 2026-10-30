/*
 *	Example of Sentinel Search in C
 *	Objective: Find a value in an array without testing all
 *values inside the loop
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 10

// Sentinel search performs a linear search without checking the key at every
// iteration of the search loop
int buscaSentinela(int vetor[], int chave) {
  vetor[TAM_VETOR] =
      chave;   // Place the searched value (key) at the end of the array
  int aux = 0; // Loop counter
  while (vetor[aux] != chave) // Increment aux until the value (key) is found
    aux++;
  if (aux == TAM_VETOR)
    return -1;
  return aux;
}

int main() {

  int vetor[TAM_VETOR + 1]; // Declare one extra array position for the sentinel
                            // used by the sentinel

  // Fill the array with random values from 0 to 1000
  srand(time(NULL));
  for (int i = 0; i < TAM_VETOR; i++) {
    vetor[i] = rand() % 1000;
    printf("%d, ", vetor[i]);
  }

  // Search using the array and the key to find
  int res = buscaSentinela(vetor, vetor[TAM_VETOR - 2]);
  if (res != -1)
    printf("\n\nValor %d encontrado na posicao %d.\n\n", vetor[res], res);
  else
    printf("\n\nValor não encontrado no vetor\n\n");

  return 0;
}
