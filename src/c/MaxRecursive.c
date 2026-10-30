/*
 * Examples of functions to find the largest number in an array
 * All 3 are recursive but only MaxDC uses divide and conquer
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Maximum using divide and conquer
int maxDivideAndConquer(int *array, int start, int end) {
  int aux1, aux2;
  int middle = (start + end) / 2;

  if (start == end) {
    return array[start];
  }

  aux1 = maxDivideAndConquer(array, start, middle);
  aux2 = maxDivideAndConquer(array, middle + 1, end);

  if (aux1 > aux2) {
    return aux1;
  } else {
    return aux2;
  }
}

void findMaximumRecursive(int *array, int maximum, int index) {
  if (array[index] > maximum) {
    maximum = array[index];
  }

  if (index < MAX - 1) {
    findMaximumRecursive(array, maximum, index + 1);
  } else {
    printf("\n\nMax1: %d\n", maximum);
  }
}

int findMaximum(int array[], int arraySize) {
  if (arraySize == 1) {
    return array[0]; // There is only one element
  } else {
    int x = findMaximum(array, arraySize - 1);

    if (x > array[arraySize - 1]) {
      return x;
    } else {
      return array[arraySize - 1];
    }
  }
}

int main() {
  int array[MAX];

  for (int i = 0; i < MAX; ++i) {
    array[i] = (rand() % 90) + 10; // 10 a 99
    printf("%d, ", array[i]);
  }

  findMaximumRecursive(array, array[0], 1);

  printf("\nMax2: %d\n", findMaximum(array, MAX));
  printf("\nMaxDC: %d\n\n", maxDivideAndConquer(array, 0, MAX - 1));

  return 0;
}
