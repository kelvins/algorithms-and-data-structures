class Countsort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
  end

  # min_max[0] = menor valor
  # min_max[1] = maior valor
  def init(array)
    min_max = array_max_min(array)
    count_sort(array, min_max[0], min_max[1])
  end

  private

  def array_max_min(array)
    array.minmax
  end

  def count_sort(array, min, max)
    if min > max
      return 'algo deu errado pqp'
    else
      n = max - min + 1
      size = array.length
      aux = Array.new(size)
      count = Array.new(n, 0)

      (0...size).each do |i|
        count[array[i] - min] += 1
      end
      (1...n).each do |i|
        count[i] += count[i - 1]
      end
      (0...size).each do |i|
        aux[count[array[i] - min] - 1] = array[i]
        count[array[i] - min] -= 1
      end
      (0...size).each do |i|
        array[i] = aux[i]
      end
    end
    @array_sorted = array
  end
end

#test
c_s = Countsort.new
c_s.init([1,4,10,2,3,32,0])
p c_s.array_sorted
