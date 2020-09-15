require "test/unit/assertions"
include Test::Unit::Assertions

#the easiest implementation would be using .reverse method


def is_palindrome(string)
    
    return true if string.size == 1 || string.size == 0

    reversed = ""
    string = string.gsub(" ", "").downcase
    string.chars.reverse_each do |c|
        reversed << c
    end
    
    reversed == string ? true : false
end

assert_equal is_palindrome("abba"), true
assert_equal is_palindrome("abbas"), false
assert_equal is_palindrome("tattarrattat"), true
assert_equal is_palindrome("Was it a palindrome?"), false
assert_equal is_palindrome("No lemon, no melon"), true