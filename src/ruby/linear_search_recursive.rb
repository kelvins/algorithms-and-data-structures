# frozen_string_literal: true

require "test/unit/assertions"
include Test::Unit::Assertions

# Return the element index, or -1 if it is not present.

def search_sequential_recursive(list, value, index = 0)
  if list[index] == value
    index
  elsif index == list.size
    -1
  else
    index += 1
    search_sequential_recursive(list, value, index)
  end
end

assert_equal search_sequential_recursive([1, 2, 3, 4, 5], 1), 0
assert_equal search_sequential_recursive(%w[a b c], 1), -1
assert_equal search_sequential_recursive([10, 9, 7, 2, 4, 5, 6, 99, 11, 4], 7), 2
