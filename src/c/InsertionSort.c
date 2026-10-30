/*
Insertion Sort algorithm in C
*/

#include <stdio.h>  // Required for input and output
#include <stdlib.h> // Required to use rand()
#include <time.h>   // Required to initialize the random number seed

// Define insertion_sort, which receives the array to sort and its size n
void insertion_sort(int arr[], int n) {
  int i, j, key;
  // Iterate over all array elements, starting with the second
  for (i = 1; i < n; i++) {
    // Store the current element in key
    key = arr[i];
    // Initialize j to the index before the current element
    j = i - 1;
    // While j is at least 0 and the current element is less than the element
    // at index j, move the element at j one position to the right and decrement
    // j
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    // When the inner loop ends, place the current element in its correct
    // position
    arr[j + 1] = key;
  }
}

// Main function
int main() {
  int i, n, arr[100];
  srand(time(NULL)); // Initialize the random number seed
  printf("Entre com o numero de elementos no vetor: ");
  scanf("%d", &n);
  printf("Vetor de entrada:\n");
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100; // Generate a random value from 0 to 99
    printf("%d ", arr[i]); // Print the generated value
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