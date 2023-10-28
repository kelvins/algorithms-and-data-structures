# frozen_string_literal: true

require 'test/unit/assertions'
include Test::Unit::Assertions

class BinaryTree
  attr_accessor :value
  attr_writer :left, :right

  def left
    @left ||= BinaryTree.new
  end

  def right
    @right ||= BinaryTree.new
  end

  def search(received_value)
    return value if value == received_value || value.nil?

    if received_value < value
      left.search(received_value)
    else
      right.search(received_value)
    end
  end

  def insert(received_value)
    return @value = received_value if value.nil?
    return left.insert(received_value) if received_value <= value

    right.insert(received_value)
  end

  def to_a
    return [] if value.nil?

    left.to_a + [value] + right.to_a
  end
end

tree = BinaryTree.new

tree.insert(42)
tree.insert(43)
tree.insert(44)

assert_equal(42, tree.search(42))
assert_equal(43, tree.search(43))
assert_equal(44, tree.search(44))
assert_equal(nil, tree.search(45))

tree = BinaryTree.new

assert_equal([], tree.to_a)

tree.insert(42)

assert_equal([42], tree.to_a)

tree.insert(43)

assert_equal([42, 43], tree.to_a)

tree.insert(41)

assert_equal([41, 42, 43], tree.to_a)
