# frozen_string_literal: true

class Quicksort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    quick_sort(array)
  end

  private

  def quick_sort(array, compare = ->(a, b) { a <=> b })
    inner(array, 0, array.length - 1, compare)
  end

  def inner(array, left, right, compare)
    if left < right
      pivot = partition_random(array, left, right, compare)
      inner(array, left, pivot - 1, compare)
      inner(array, pivot + 1, right, compare)
    end
    @array_sorted = array
  end

  def partition_random(array, left, right, compare)
    pivot = left + (rand * (right - left)).floor
    array[right], array[pivot] = array[pivot], array[right] if pivot != right
    partition_right(array, left, right, compare)
  end

  def partition_right(array, left, right, compare)
    pivot = array[right]
    mid = left
    (mid..right - 1).each do |i|
      next unless compare.call(array[i], pivot) <= 0

      array[i], array[mid] = array[mid], array[i] if i != mid
      mid += 1
    end
    array[right], array[mid] = array[mid], array[right] if right != mid
    mid
  end
end

# test
q_s = Quicksort.new
q_s.init([1, 4, 10, 2, 3, 32, 0])
p q_s.array_sorted
