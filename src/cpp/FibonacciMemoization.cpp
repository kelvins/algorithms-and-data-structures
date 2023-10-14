#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int fibonacciMemoization(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);
    return memo[n];
}

int main() {
    int test_nbr = 12;

    // Initialize the memoization table with -1 (uncomputed)
    memo.assign(test_nbr + 1, -1);

    cout << "memoization: " << fibonacciMemoization(test_nbr) << endl;
    return 0;
}
