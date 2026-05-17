/*
 *  Insertion Sort algorithm in C
 */

#include <stdio.h>   // Required for input and output
#include <stdlib.h>  // Required for rand() function
#include <time.h>    // Required to initialize random number seed

// We define the insertion_sort function that takes the array to be sorted
// and its size n as arguments
void insertion_sort(int arr[], int n) {
  int i, j, key;
  // We iterate through all elements of the array starting from the second element
  for (i = 1; i < n; i++) {
    // We store the value of the current element in key
    key = arr[i];
    // We initialize index j as the element before the current element
    j = i - 1;
    // While j is greater than or equal to 0 and the current element is less than
    // the element at position j of the array, we move the element at position j
    // one position to the right and decrement j
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    // When the inner loop ends, we place the current element in its correct position
    arr[j + 1] = key;
  }
}

// Main function
int main() {
  int i, n, arr[100];
  srand(time(NULL)); // Initialize random number seed
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  printf("Input array:\n");
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100; // Generate a random value between 0 and 99
    printf("%d ", arr[i]); // Print the generated value
  }
  printf("\n");
  insertion_sort(arr, n);
  printf("Array sorted in ascending order:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
