# frozen_string_literal: true

def binary_search(value, array, left, right)
  middle = ((left + right) / 2).floor

  return -1 unless left <= right

  if value > array[middle]
    binary_search(value, array, middle + 1, right)
  elsif value < array[middle]
    binary_search(value, array, left, middle - 1)
  else
    middle
  end
end

array = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
puts binary_search(12, array, 0, array.length)

