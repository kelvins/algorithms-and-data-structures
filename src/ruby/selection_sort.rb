# frozen_string_literal: true

# Sort an array using the SelectionSort algorithm
class SelectionSort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    selection_sort(array, array.length - 1)
  end

  private

  def selection_sort(array, size)
    size.times do |i|
      index_min = i

      (i + 1).upto(size) do |j|
        index_min = j if array[j] < array[index_min]
      end
      array[i], array[index_min] = array[index_min], array[i] if index_min != i
    end
    @array_sorted = array
  end
end

# test
s_s = SelectionSort.new
s_s.init([1, 4, 10, 2, 3, 32, 0])
p s_s.array_sorted
