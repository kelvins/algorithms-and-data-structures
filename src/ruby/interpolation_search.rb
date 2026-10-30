# frozen_string_literal: true

# Interpolation search algorithm in Ruby
# Carlos Alves
# https://github.com/EuCarlos

def interpolation_search(value, data)
  low = 0
  high = data.length - 1
  mid = ((data.length - 1) / 2).floor + low

  while low < mid
    if data[mid] == value
      return "Element found at position #{high} in the sorted array."
    elsif value > data[mid]
      low = mid
      mid = ((high - low) / 2).floor + low
    else
      high = mid
      mid = ((high - low) / 2).floor + low
    end
  end
end

def main
  array1 = [37, 53, 1, 43, 11, 49, 32, 55, 40, 47, 25, 4].sort
  puts interpolation_search(43, array1) # 8th position in the sorted array

  array2 = [23, 9, 5, 78, 123, 5444, 54_535, 64, 3, 12, 14, 15].sort
  puts interpolation_search(5444, array2) # 11th position in the sorted array
end

main
