# frozen_string_literal: true

# Recursive maximum algorithm in Ruby
# Carlos Alves
# https://github.com/EuCarlos

def max_recursive(array, maximum, index)
  maximum = array[index] if array[index] > maximum

  maximum = max_recursive(array, maximum, index + 1) if index < array.length - 1

  maximum
end

list = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
print list

puts "\nRecursive maximum: #{max_recursive(list, list[0], 0)}"
