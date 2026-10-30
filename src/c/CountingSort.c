#include <stdio.h>
#include <stdlib.h>

// CountingSort - Sorting by Counting - Matheus Martins Batista -
// Federal University of Itajuba - 2021

// Need to find the largest element to allocate the auxiliary counting
// array
int findMax(int *arr, int size) {
  int maximum = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }

  return maximum;
}

// Sorts the values present in A and stores them in B
void countingSort(int *arrA, int *arrB, int size) {
  // Count array will have the frequency that a number appears in the array
  // must set 0 for all elements or use calloc
  int maximum = findMax(arrA, size);
  int *count = calloc(maximum + 1, sizeof(int));

  // Frequency that a given value appears in the array
  for (int i = 0; i < size; i++) {
    count[arrA[i]]++;
  }

  // Cumulative frequency of values less than element i of the original
  // array (A)
  for (int i = 1; i <= maximum; i++) {
    count[i] += count[i - 1];
  }

  // Traverse the original array starting from the last element, replacing
  // indices in the count array elements and decrementing with each assignment
  for (int i = size - 1; i >= 0; i--) {
    arrB[count[arrA[i]] - 1] = arrA[i];
    count[arrA[i]]--;
  }
}

int main() {
  int *arrA, *arrB;
  int size = 10;
  arrA = malloc(size * sizeof(int));
  arrB = calloc(size, sizeof(int));

  // Populate array A
  srand(48 + size);
  for (int j = 0; j < size; j++)
    arrA[j] = rand() % 100;

  countingSort(arrA, arrB, size);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arrB[i]);
  }

  return 0;
}
