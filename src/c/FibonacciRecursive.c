#include <stdio.h>

int fibonacci(int number) {
  if (number == 0) {
    return 0;
  } else if (number == 1) {
    return 1;
  } else {
    return fibonacci(number - 1) + fibonacci(number - 2);
  }
}

int main(void) {
  int test_nbr = 12;

  printf("recursive: %d\n", fibonacci(test_nbr));
  return 0;
}
