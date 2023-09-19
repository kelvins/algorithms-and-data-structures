#include <iostream>

long long int exp(int n, int pow) {

    if(pow == 0) 
        return 1;

    return n * exp(n, pow-1);
}


int main() {

    long long int n, pow;

    std::cin >> n >> pow;

    n = exp(n, pow);
    std::cout << n << std::endl;
    

    return 0;
}
