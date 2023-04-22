# frozen_string_literal: true

# Sort an array using the InsertionSort algorithm
class InsertionSort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    insertion_sort(array)
  end

  private

  def insertion_sort(array, compare = ->(a, b) { a <=> b })
    return nil if array.empty?

    (1..array.length - 1).each do |i|
      item = array[i]
      index_hole = i
      while index_hole.positive? && compare.call(array[index_hole - 1], item).positive?
        array[index_hole] = array[index_hole - 1]
        index_hole -= 1
      end
      array[index_hole] = item
    end
    @array_sorted = array
  end
end

# test
i_s = InsertionSort.new
i_s.init([1, 4, 10, 2, 3, 32, 0])
p i_s.array_sorted
