#include <stdio.h>

int fibonacci_recursive(int number) {
    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
    }
}

int main(void) {
    int test_nbr = 12;
  
    printf("recursive: %d\n", fibonacci_recursive(test_nbr));
    return 0;
}
