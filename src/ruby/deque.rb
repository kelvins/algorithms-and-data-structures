# frozen_string_literal: true

# Deque algorithm in Ruby
# Carlos Alves
# https://github.com/EuCarlos

# Implement Deque data structure
class Deque
  attr_accessor :deque

  def initialize(deque = [])
    self.deque = deque
  end

  # adds an item in front of the deque:
  def insert_front(value)
    deque.unshift(value)
  end

  # adds an item at the back of the deque:
  def insert_last(value)
    deque.push(value)
  end

  # removes an item from the front of the deque:
  def delete_front
    deque.shift unless deque.empty?
  end

  # removes an item from the back of the deque:
  def delete_last
    deque.pop unless deque.empty?
  end

  # gets the item at the front of the deque:
  def read_front
    deque.length >= 1 ? deque[0] : "List is empty"
  end

  # gets the item at the back of the deque:
  def read_rear
    deque.length >= 1 ? deque[-1] : "List is empty"
  end

  # checks whether deque is full:
  def full?
    result = deque.length >= 1 ? "is" : "is not"
    "List #{result} full!"
  end

  # checks whether deque is empty:
  def empty?
    result = deque.empty? ? "is" : "is not"
    "List #{result} empty"
  end
end

def main
  # test with full list
  deque = Deque.new([86, 16, 10, 39])

  deque.insert_front(54)
  deque.insert_last(91)

  deque.delete_front
  deque.delete_last

  puts deque.read_front
  puts deque.read_rear

  puts deque.full?
  puts deque.empty?

  # test with empty list
  deque_empty = Deque.new
  puts deque_empty.full?
  puts deque_empty.empty?
end

main
