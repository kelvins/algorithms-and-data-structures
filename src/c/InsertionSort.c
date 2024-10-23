/*
Algoritmo de ordenação Insertion Sort em C
*/

#include <stdio.h>  // Necessário para usar input e output
#include <stdlib.h> // Necessário para usar a função rand()
#include <time.h> // Necessário para inicializar a semente de números aleatórios

// Definimos a função insertion_sort que recebe como argumento o vetor a ser
// ordenado e seu tamanho n
void insertion_sort(int arr[], int n) {
  int i, j, key;
  // Percorremos todos os elementos do vetor a partir do segundo elemento
  for (i = 1; i < n; i++) {
    // Armazenamos o valor do elemento atual em key
    key = arr[i];
    // Inicializamos o índice j como o elemento anterior ao elemento atual
    j = i - 1;
    // Enquanto j é maior ou igual a 0 e o elemento atual é menor do que o
    // elemento na posição j do vetor, movemos o elemento na posição j uma
    // posição para a direita e decrementamos j
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    // Quando o loop interno termina, colocamos o elemento atual em sua posição
    // correta
    arr[j + 1] = key;
  }
}

// Função principal
int main() {
  int i, n, arr[100];
  srand(time(NULL)); // Inicializa a semente de números aleatórios
  printf("Entre com o numero de elementos no vetor: ");
  scanf("%d", &n);
  printf("Vetor de entrada:\n");
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100; // Gera um valor aleatório entre 0 e 99
    printf("%d ", arr[i]); // Imprime o valor gerado
  }
  printf("\n");
  insertion_sort(arr, n);
  printf("Vetor ordenado em ordem crescente:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}