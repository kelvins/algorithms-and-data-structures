#include <stdio.h>

int fibonacci(int number) {
    int last_number = 0;
    int current_number = 1;

    for (int index = 0; index < number; ++index) {
        int temp = current_number;
        current_number += last_number;
        last_number = temp;
    }
    return last_number;
}

int main() {
    printf("Fibonacci Iterative: %d\n", fibonacci(12));
    return 0;
}
