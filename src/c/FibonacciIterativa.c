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

int main(void) {
    int test_nbr = 12;

    printf("iterative: %d\n", fibonacci_iterative(test_nbr));
    return 0;
}
