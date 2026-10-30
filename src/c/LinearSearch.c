#include <stdio.h>

int linearSearch(int array[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {

  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Value %d at index %d\n", 3, linearSearch(a, n, 3));
  printf("Value %d at index %d\n", 9, linearSearch(a, n, 9));
}
