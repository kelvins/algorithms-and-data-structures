#include <iostream>

int factorial(int n) {

  if (n == 0)
    return 1;

  else
    return n * (factorial(n - 1));
}

int main() {

  int nums[] = {0, 1, 2, 3, 4, 5};

  for (auto i : nums) {
    std::cout << std::to_string(i) + "! = " << factorial(i) << std::endl;
  }

  return 0;
}
