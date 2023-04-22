# frozen_string_literal: true

require "test/unit/assertions"
include Test::Unit::Assertions

# the easiest implementation would be using .reverse method

def palindrome?(string)
  return true if string.size == 1 || string.empty?

  reversed = ''
  string = string.gsub(' ', '').downcase
  string.chars.reverse_each do |c|
    reversed << c
  end

  reversed == string
end

assert_equal palindrome?('abba'), true
assert_equal palindrome?('abbas'), false
assert_equal palindrome?('tattarrattat'), true
assert_equal palindrome?('Was it a palindrome?'), false
assert_equal palindrome?('No lemon, no melon'), true
