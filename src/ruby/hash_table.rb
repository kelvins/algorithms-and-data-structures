# frozen_string_literal: true

class HashTable
  attr_reader :hash

  def initialize(size = 500)
    @hash = Array.new(size) { [] }
    @size = size
  end

  def put(key, value)
    idx = calculate_hash(key)
    @hash[idx] << [key, value]
  end

  def get(key)
    idx = calculate_hash(key)

    bucket = @hash[idx]
    pair = bucket.find { |pair| pair[0] == key }

    pair[1] if pair
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
hash.put(:code, "ABC123")
hash.put(:mode, "dark")

puts "Code is #{hash.get(:code)}" # => ABC123
puts "Mode is #{hash.get(:mode)}" # => "dark

hash.delete(:code)
puts hash.get(:code) # => nil
