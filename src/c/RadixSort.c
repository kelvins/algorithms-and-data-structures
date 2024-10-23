#include <stdio.h>

void print_array(int array[], int size) {
  printf("[ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

int get_max(int array[], int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  return max;
}

void radix_sort(int array[], int size) {
  int i;
  int semi_sorted[size];
  int significant_digit = 1;
  int largest_number = get_max(array, size);

  while (largest_number / significant_digit > 0) {
    int bucket[10] = {0};
    for (i = 0; i < size; i++) {
      bucket[(array[i] / significant_digit) % 10]++;
    }
    for (i = 1; i < 10; i++) {
      bucket[i] += bucket[i - 1];
    }
    for (i = size - 1; i >= 0; i--) {
      semi_sorted[--bucket[(array[i] / significant_digit) % 10]] = array[i];
    }
    for (i = 0; i < size; i++) {
      array[i] = semi_sorted[i];
    }
    significant_digit *= 10;
  }
}

int main() {
  int array[10] = {45, 75, 89, 12, 34, 9, 67, 23, 90, 11};
  printf("Unsorted Array\n");
  print_array(array, 10);

  radix_sort(array, 10);

  printf("Sorted Array\n");
  print_array(array, 10);
  return 0;
}
