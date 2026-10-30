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

#define ARRAY_SIZE 100

void merge(int array[], int size) {
  int middle = size / 2;
  int i = 0, j = middle, k = 0;
  int temporary[size];

  while (i < middle && j < size) {
    if (array[i] <= array[j])
      temporary[k] = array[i++];
    else
      temporary[k] = array[j++];
    k++;
  }

  if (i == middle)
    while (j < size)
      temporary[k++] = array[j++];
  else
    while (i < middle)
      temporary[k++] = array[i++];

  for (i = 0; i < size; i++)
    array[i] = temporary[i];
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

  // Fill the array with random values from 0 to 1000
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