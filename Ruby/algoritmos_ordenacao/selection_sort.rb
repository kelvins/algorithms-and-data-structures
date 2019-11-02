class Selectionsort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    selection_sort(array, array.length - 1)
  end

  private

  def selection_sort(array, n)
    n.times do |i|
      index_min = i

      (i + 1).upto(n) do |j|
        index_min = j if array[j] < array[index_min]
      end
      array[i], array[index_min] = array[index_min], array[i] if index_min != i
    end
    @array_sorted = array
  end
end

#test
s_s = Selectionsort.new
s_s.init([1,4,10,2,3,32,0])
p s_s.array_sorted
