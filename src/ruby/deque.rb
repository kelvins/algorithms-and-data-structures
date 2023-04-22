# frozen_string_literal: true

# Algoritmo Deque em Ruby
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

  # adds an item in back of the deque:
  def insert_last(value)
    deque.push(value)
  end

  # adds an item in front of the deque:
  def delete_front
    deque.shift unless deque.empty?
  end

  # adds an item in back of the deque:
  def delete_last
    deque.pop unless deque.empty?
  end

  # gets the item at the front of the queue:
  def read_front
    deque.length >= 1 ? deque[0] : 'Lista está vazia'
  end

  # gets the item at the last of the queue:
  def read_rear
    deque.length >= 1 ? deque[-1] : 'Lista está vazia'
  end

  # checks whether deque is full or not
  def full?
    result = deque.length >= 1 ? 'está' : 'não esta'
    "Lista #{result} cheia!"
  end

  # checks whether deque is empty or not
  def empty?
    result = deque.empty? ? 'está' : 'não esta'
    "Lista #{result} vazia"
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
