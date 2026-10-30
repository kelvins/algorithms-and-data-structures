#include <stdio.h>
#include <stdlib.h>

/*
 *	Examples of functions to return the factorial of a number n
 *	recursive function
 */

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int result = factorial(num);
  printf("1 => ");
  printf("%d! é : %d\n", num, result);
  return (0);
}

int factorial(int num) {
  if (num <= 1) {
    return 1;
  }
  printf("%d * ", num);
  return num * factorial(num - 1);
}
