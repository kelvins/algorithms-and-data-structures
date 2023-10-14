#include <stdio.h>

#define MAX_N 100 // Define the maximum number for which you want to calculate Fibonacci

int memo[MAX_N]; // Memoization table to store computed values

int fibonacci_memoization(int number) {
    if (number <= 1) {
        return number;
    }
    if (memo[number] != -1) {
        return memo[number];
    }

    memo[number] = fibonacci_memoization(number - 1) + fibonacci_memoization(number - 2);
    return memo[number];
}

int main(void) {
    int test_nbr = 12;

    // Initialize the memoization table with -1 (uncomputed)
    for (int i = 0; i < MAX_N; i++) {
        memo[i] = -1;
    }

    printf("memoization: %d\n", fibonacci_memoization(test_nbr));
    return 0;
}
