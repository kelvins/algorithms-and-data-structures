#include <stdio.h>

int linearSearchRecursive(int array[], int i, int target, int size) {

  if (i == size) {
    return -1;
  } else if (array[i] == target) {
    return i;
  } else {
    return linearSearchRecursive(array, i + 1, target, size);
  }
}

int main() {

  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  size_t n = sizeof(array) / sizeof(array[0]);
  printf("Value %d at index %d\n", 1, linearSearchRecursive(array, 0, 1, n));
  printf("Value %d at index %d\n", 10, linearSearchRecursive(array, 0, 10, n));
}
