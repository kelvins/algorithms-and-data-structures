#include <stdio.h>

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If the right child is larger than the largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If the largest element is not the root
  if (largest != i) {
    // Swap the largest element with the root
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n) {
  // Build a max heap
  int i;
  for (i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract elements from the heap
  for (i = n - 1; i > 0; i--) {
    // Move the current root to the end
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {12, 21, 13, 5, 1, 7};
  int i;
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  heapsort(arr, n);

  printf("\nSorted array: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
