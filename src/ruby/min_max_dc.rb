# frozen_string_literal: true

require "test/unit/assertions"
include Test::Unit::Assertions

def min_max_dc(vector, start_index, end_index)
  if start_index == end_index
    return [vector[start_index], vector[start_index]]
  end

  middle = (start_index + end_index) / 2
  left_min, left_max = min_max_dc(vector, start_index, middle)
  right_min, right_max = min_max_dc(vector, middle + 1, end_index)

  min = left_min < right_min ? left_min : right_min
  max = left_max > right_max ? left_max : right_max

  [min, max]
end

assert_equal([1, 5], min_max_dc([1, 2, 3, 4, 5], 0, 4))
assert_equal([14, 55], min_max_dc([13, 55, 42, 14, 15], 1, 3))
assert_equal([13, 13], min_max_dc([13, 55, 42, 14, 15], 0, 0))
assert_equal([14, 15], min_max_dc([13, 55, 42, 14, 15], 3, 4))
