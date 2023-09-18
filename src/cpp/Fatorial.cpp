#include <iostream>

int factorial(int n) {

    int fact = 1;
    for (size_t i = 1; i <= n; i++) {
        fact = i*fact;
    }

    return fact;
}

int main() {

    int nums[] = {0, 1, 2, 3, 4, 5};

    for(auto i : nums) {
        std::cout << std::to_string(i)+"! = " << factorial(i) << std::endl; 
    }

    return 0;
}
