#include <stdio.h>

int fibonacci_iterative(int number) {
    int last_number = 0;
    int current_number = 1;

    for (int index = 0; index < number; ++index) {
        int temp = current_number;
        current_number += last_number;
        last_number = temp;
    }
    return last_number;
}

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

    printf("iterative: %d\n", fibonacci_iterative(test_nbr));
    printf("recursive: %d\n", fibonacci_recursive(test_nbr));
    return 0;
}
