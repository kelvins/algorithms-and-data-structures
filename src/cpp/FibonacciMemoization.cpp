#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int test_nbr = 12;

    // Initialize the memoization table with -1 (uncomputed)
    memo.assign(test_nbr + 1, -1);

    cout << "memoization: " << fibonacci(test_nbr) << endl;
    return 0;
}
