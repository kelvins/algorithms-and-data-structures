class Bubblesort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    bubble_sort(array)
  end

  private

  def bubble_sort(array)
    return nil if array.empty?
    n = array.length - 1
    loop do
      swapped = false

      n.times do |i|
        if array[i] > array[i + 1]
          array[i], array[i + 1] = array[i + 1], array[i]
          swapped = true
        end
      end
      break unless swapped
    end
    @array_sorted = array
  end
end

# test
b_s = Bubblesort.new
b_s.init([1,4,10,2,3,32,0])
p b_s.array_sorted
