#include <iostream>


int main() {

    long long int n, exp;

    std::cin >> n >> exp;

    long long int result = 1;

    for (long long int i = 0; i < exp; i++) {
        result *= n;
    }

    std::cout << result << std::endl;
    

    return 0;
}
