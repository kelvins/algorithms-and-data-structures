# frozen_string_literal: true

# Iterative minimum and maximum in Ruby
# Carlos Alves
# https://github.com/EuCarlos

def min_max_array(array)
  minimum = array[0]
  maximum = array[0]

  array_size = array.length - 1
  (1..array_size).each do |i|
    if array[i] < minimum
      minimum = array[i]
    elsif array[i] > maximum
      maximum = array[i]
    end
  end

  puts "Minimum: #{minimum}"
  puts "Maximum: #{maximum}"
end

list = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(list)
