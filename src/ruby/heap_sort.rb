class Heapsort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  def init(array)
    heap_sort(array)
  end

  private

  def heap_sort(array)
    n = array.length
    a = [nil] + array

    (n / 2).downto(1) do |i|
      heapify(a, i, n)
    end
    while n > 1
      a[1], a[n] = a[n], a[1]
      n -= 1
      heapify(a, 1, n)
    end
    a.drop(1)
    @array_sorted = a
  end

  def heapify(array, parent, limit)
    root = array[parent]
    while (child = 2 * parent) <= limit
      child += 1 if child < limit && array[child] < array[child + 1]
      break if root >= array[child]
      array[parent] = array[child]
      parent = child
      array[parent] = root
    end
  end
end

#test
h_s = Heapsort.new
h_s.init([1,4,10,2,3,32,0])
p h_s.array_sorted
