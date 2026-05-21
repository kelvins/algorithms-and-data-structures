/*
 *  Example of sorting using Merge Sort
 *
 *  Divide and conquer:
 *
 *  Divide: Split the data into small subsequences;
 *  Conquer: Sort the two halves recursively by applying merge sort;
 *  Combine: Join the two halves into a single sorted set.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void merge(int array[], int size) {
  int middle = size / 2;
  int i = 0, j = middle, k = 0;
  int aux[size];

  while (i < middle && j < size) {
    if (array[i] <= array[j])
      aux[k] = array[i++];
    else
      aux[k] = array[j++];
    k++;
  }

  if (i == middle)
    while (j < size)
      aux[k++] = array[j++];
  else
    while (i < middle)
      aux[k++] = array[i++];

  for (i = 0; i < size; i++)
    array[i] = aux[i];
}

int mergeSort(int array[], int size) {
  int middle = size / 2;

  if (size > 1) {
    mergeSort(array, middle);
    mergeSort(array + middle, size - middle);
    merge(array, size);
  }
}

int main() {
  int array[ARRAY_SIZE];

  // Fill the array with random values 0-1000
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 1000;
    printf("%d, ", array[i]);
  }

  printf("\n\n");

  mergeSort(array, ARRAY_SIZE);

  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d, ", array[i]);
  }

  return 0;
}
