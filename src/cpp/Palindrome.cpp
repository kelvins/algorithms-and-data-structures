/*
isPalindrome Algorithm in C++
Ricardo Ferreira Carvalheira - 2023
https://github.com/ricardocarva

    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include <iostream>

#include <string>

using namespace std;

bool isPalindrome(string s) {
    // Step 1: Convert all characters to lowercase
    for (char& c : s) {
        c = std::tolower(c);
    }

    // Step 2: Remove non-alphanumeric characters
    std::string alphanumericStr;
    for (char c : s) {
        if (std::isalnum(c)) {
            alphanumericStr.push_back(c);
        }
    }

    // Step 3: Check if the resulting string is a palindrome
    int left = 0;
    int right = alphanumericStr.length() - 1;

    while (left < right) {
        if (alphanumericStr[left] != alphanumericStr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline (std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    }
    else {
        std::cout << "The string is not a palindrome." << std::endl;
    }
    return 0;
}