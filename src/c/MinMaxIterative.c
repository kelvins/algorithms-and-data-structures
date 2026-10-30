#include <stdio.h>

int main() {
  int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  int minimum = array[0];
  int maximum = array[0];

  size_t length = sizeof(array) / sizeof(array[0]);

  for (int i = 1; i < length; ++i) {
    if (array[i] < minimum) {
      minimum = array[i];
    }
    if (array[i] > maximum) {
      maximum = array[i];
    }
  }

  printf("min: %d\n", minimum);
  printf("max: %d\n", maximum);
  return 0;
}
