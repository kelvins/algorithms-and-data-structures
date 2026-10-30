#include <stdio.h>

int exponentiation(int base, int exponent) {

  int i;
  int result = base;

  for (i = 0; i < exponent - 1; i++)
    result *= base;

  return result;
}

int main() {

  printf("%d\n", exponentiation(5, 3));

  return 0;
}
