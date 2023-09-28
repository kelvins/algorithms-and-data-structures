class HashTable
  attr_reader :hash

  def initialize(size = 500)
    @hash = Array.new
    @size = size
  end

  def put(key, value)
    idx = calculate_hash(key)
    @hash[idx] = value
  end

  def get(key)
    idx = calculate_hash(key)
    @hash[idx]
  end

  def delete(key)
    idx = calculate_hash(key)
    @hash.delete_at(idx)
  end

  private

  def calculate_hash(str)
    str.to_s.bytes.reduce(&:*) % @size
  end
end

hash = HashTable.new
hash.put(:name, 'Jane')
hash.put(:age, 22)

puts hash.get(:name) # => Jane
puts hash.get(:age) # => 22

hash.delete(:name)
puts hash.get(:name) # => nil
