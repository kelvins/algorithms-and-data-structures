#include <iostream>

using namespace std;

int fibonacci(int n) {
    int last = 0;
    int curr = 1;
    for (int index = 0; index < n; ++index) {
        int temp = curr;
        curr += last;
        last = temp;
    }
    return last;
}

int main() {
    cout << fibonacci(12) << endl;
}
