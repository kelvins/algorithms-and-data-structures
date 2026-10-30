/*
 *	Example of Sentinel Search in C
 *	Objective: Find a value in an array without testing all
 *values inside the loop
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Sentinel search performs a linear search without checking the key at every
// iteration of the search loop
int sentinelSearch(int array[], int key) {
  array[ARRAY_SIZE] =
      key;           // Place the searched value (key) at the end of the array
  int temporary = 0; // Loop counter
  while (array[temporary] !=
         key) // Increment aux until the value (key) is found
    temporary++;
  if (temporary == ARRAY_SIZE)
    return -1;
  return temporary;
}

int main() {

  int array[ARRAY_SIZE + 1]; // Declare one extra array position for the
                             // sentinel used by the sentinel

  // Fill the array with random values from 0 to 1000
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 1000;
    printf("%d, ", array[i]);
  }

  // Search using the array and the key to find
  int res = sentinelSearch(array, array[ARRAY_SIZE - 2]);
  if (res != -1)
    printf("\n\nValue %d found at position %d.\n\n", array[res], res);
  else
    printf("\n\nValue not found in the array\n\n");

  return 0;
}
