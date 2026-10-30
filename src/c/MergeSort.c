/*
 *	Example of Sorting using Merge Sort
 *
 *	Divide and conquer:
 *
 *	Divide: Split the data into smaller subsequences;
 *	Conquer: Sort both halves recursively by applying merge
 *sort; Combine: Join the two halves into a single sorted collection.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 100

void merge(int vetor[], int tamanho) {
  int meio = tamanho / 2;
  int i = 0, j = meio, k = 0;
  int aux[tamanho];

  while (i < meio && j < tamanho) {
    if (vetor[i] <= vetor[j])
      aux[k] = vetor[i++];
    else
      aux[k] = vetor[j++];
    k++;
  }

  if (i == meio)
    while (j < tamanho)
      aux[k++] = vetor[j++];
  else
    while (i < meio)
      aux[k++] = vetor[i++];

  for (i = 0; i < tamanho; i++)
    vetor[i] = aux[i];
}

int mergeSort(int vetor[], int tamanho) {
  int meio = tamanho / 2;

  if (tamanho > 1) {
    mergeSort(vetor, meio);
    mergeSort(vetor + meio, tamanho - meio);
    merge(vetor, tamanho);
  }
}

int main() {

  int vetor[TAM_VETOR];

  // Fill the array with random values from 0 to 1000
  srand(time(NULL));
  for (int i = 0; i < TAM_VETOR; i++) {
    vetor[i] = rand() % 1000;
    printf("%d, ", vetor[i]);
  }

  printf("\n\n");

  mergeSort(vetor, TAM_VETOR);

  for (int i = 0; i < TAM_VETOR; i++) {
    printf("%d, ", vetor[i]);
  }

  return 0;
}