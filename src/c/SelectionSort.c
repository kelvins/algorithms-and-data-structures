#include <stdio.h>

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void selection_sort(int array[], int n) {
  int min, i, j;
  for (i = 0; i < n; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (array[min] > array[j]) {
        min = j;
      }
    }
    if (min != i)
      swap(array, min, i);
  }
}

int main() {
  int array_size = 10;
  int array[10] = {45, 7, 125, 18, 3, 5, 11, 107, 60, 4};

  selection_sort(array, array_size);

  printf("Sorted Array:\n");
  int i;
  for (i = 0; i < array_size; i++)
    printf("%d ", array[i]);

  return 0;
}