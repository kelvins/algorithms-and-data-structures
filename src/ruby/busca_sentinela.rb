# frozen_string_literal: true
def sentinel_search(value, array)
  # Create a copy of the array
  array_copy = array.dup

  # Add the value to the end of the array copy
  array_copy.push(value)
  index = 0

  # While it's not the value, increment by 1
  index += 1 while array_copy[index] != value

  # Remove the value from the end of the array copy
  array_copy.pop

  # If the index variable equals the array size, return -1
  return -1 if index == array_copy.length

  # Otherwise, return the position of the value in the array copy
  index
end

array = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts sentinel_search(98, array)