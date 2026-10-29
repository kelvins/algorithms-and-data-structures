#include <stdio.h>
#include <stdlib.h>

// CountingSort - Sorting by Counting - Matheus Martins Batista -
// Federal University of Itajuba - 2021

// Need to find the largest element to allocate the auxiliary counting
// array
int findMax(int *arr, int tam) {
  int max = arr[0];

  for (int i = 1; i < tam; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

// Sorts the values present in A and stores them in B
void countingSort(int *arrA, int *arrB, int tam) {
  // Count array will have the frequency that a number appears in the array
  // must set 0 for all elements or use calloc
  int max = findMax(arrA, tam);
  int *count = calloc(max + 1, sizeof(int));

  // Frequency that a given value appears in the array
  for (int i = 0; i < tam; i++) {
    count[arrA[i]]++;
  }

  // Cumulative frequency of values less than element i of the original
  // array (A)
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Traverse the original array starting from the last element, replacing
  // indices in the count array elements and decrementing with each assignment
  for (int i = tam - 1; i >= 0; i--) {
    arrB[count[arrA[i]] - 1] = arrA[i];
    count[arrA[i]]--;
  }
}

int main() {
  int *arrA, *arrB;
  int tam = 10;
  arrA = malloc(tam * sizeof(int));
  arrB = calloc(tam, sizeof(int));

  // Populate array A
  srand(48 + tam);
  for (int j = 0; j < tam; j++)
    arrA[j] = rand() % 100;

  countingSort(arrA, arrB, tam);

  printf("Sorted array: ");
  for (int i = 0; i < tam; i++) {
    printf("%d ", arrB[i]);
  }

  return 0;
}
