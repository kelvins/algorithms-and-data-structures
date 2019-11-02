require_relative './insertion_sort.rb'

class Bucketsort
  attr_reader :array_sorted

  def initialize
    @array_sorted = []
    @insertion = Insertionsort.new
  end

  def init(array)
    bucket_sort(array, array.length)
  end

  private

  def bucket_sort(array, bucket_size)
    return nil if array.empty?
    min, max = array.min, array.max
    bucket_count = ((max - min) / bucket_size).floor + 1
    buckets = Array.new(bucket_count)

    (0..buckets.length - 1).each do |i|
      buckets[i] = []
    end
    (0..array.length - 1).each do |i|
      buckets[((array[i] - min) / bucket_size).floor].push(array[i])
    end
    array.clear
    (0..buckets.length - 1).each do |i|
      @insertion.init(buckets[i])
      buckets[i].each do |value|
        array.push(value)
      end
    end
    @array_sorted = array
  end
end

# test
bu_s = Bucketsort.new
bu_s.init([1,4,10,2,3,32,0])
p bu_s.array_sorted
