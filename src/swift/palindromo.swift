//
//  palindromo.swift
//
//  Created by Matheus Torres on 14/11/20.
//

import Foundation

func isPalindrome(_ string: String) -> Bool {
    let lowercasedString: String = string.lowercased().replacingOccurrences(of: " ", with: "")
    let reversedString = String(lowercasedString.reversed())
    return (lowercasedString == reversedString)
}

print(isPalindrome(""))
print(isPalindrome("a"))
print(isPalindrome("abba"))
print(isPalindrome("abbas"))
print(isPalindrome("tattarrattat"))
print(isPalindrome("Was it a palindrome?"))
print(isPalindrome("No lemon, no melon"))

