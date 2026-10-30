#include <stdio.h>

int exponentiation(int base, int exponent) {

  if (exponent == 0)
    return 1;

  return (base * exponentiation(base, exponent - 1));
}

int main() {

  printf("%d\n", exponentiation(5, 3));

  return 0;
}
