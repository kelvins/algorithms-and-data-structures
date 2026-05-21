#include <stdio.h>
#include <stdlib.h>

/*
 *  Example function to return the factorial of a number n
 *  Recursive function
 */

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int result = fatorial(num);
  printf("1 => ");
  printf("%d! is: %d\n", num, result);
  return (0);
}

int fatorial(int num) {
  if (num <= 1) {
    return 1;
  }
  printf("%d * ", num);
  return num * fatorial(num - 1);
}
