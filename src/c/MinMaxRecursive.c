/*
 *	Example of recursive algorithm.
 *	Objective: find the maximum and minimum value in an array, using
 *recursion
 */

#include <stdio.h>

#define TAM 10

void minMaxRecursive(int array[], int minimum, int maximum, int index) {
  if (array[index] < minimum)
    minimum = array[index];
  if (array[index] > maximum)
    maximum = array[index];
  if (index < TAM - 1)
    minMaxRecursive(array, minimum, maximum, index + 1);
  else
    printf("Min: %d \nMax: %d\n\n", minimum, maximum);
}

int main() {
  int array[TAM] = {9, 2, 1, 8, 6, 3, 4, 5, 0, 7};
  minMaxRecursive(array, array[0], array[0], 0);
  return 0;
}