/*
* Example of Sorting using Merge Sort
* Kelvin Salton do Prado - 2015
*
* Divide and Conquer:
*
* Divide: Divide the data into small subsequences;
* Conquer: Sort the two halves recursively using merge sort;
* Combine: Merge the two halves into a single sorted set.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void merge(int array[], int size) {
  int middle = size / 2;
  int i = 0, j = middle, k = 0;
  int auxiliary[size];

  while (i < middle && j < size) {
    if (array[i] <= array[j])
      auxiliary[k] = array[i++];
    else
      auxiliary[k] = array[j++];
    k++;
  }

  if (i == middle)
    while (j < size)
      auxiliary[k++] = array[j++];
  else
    while (i < middle)
      auxiliary[k++] = array[i++];

  for (i = 0; i < size; i++)
    array[i] = auxiliary[i];
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
