#include <iostream>

int fatorial(int n) {

    if(n == 0) 
        return 1;

    else
        return n * (fatorial(n-1));

}

int main() {

    int nums[] = {0, 1, 2, 3, 4, 5};

    for(auto i : nums) {
        std::cout << std::to_string(i)+"! = " << fatorial(i) << std::endl; 
    }

    return 0;
}
