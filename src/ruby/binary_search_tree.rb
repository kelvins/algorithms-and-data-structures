# frozen_string_literal: true

class BinarySearchTree
  class Node
    attr_accessor :left, :right, :value

    def initialize(value)
      @left = nil
      @right = nil
      @value = value
    end
  end

  def initialize
    @root = nil
  end

  attr_reader :root

  def insert(value)
    new_node = Node.new(value)

    if @root.nil?
      @root = new_node
      return self
    end

    current_node = @root

    loop do
      if value < current_node.value
        if current_node.left.nil?
          current_node.left = new_node
          return self
        end
        current_node = current_node.left
      else
        if current_node.right.nil?
          current_node.right = new_node
          return self
        end
        current_node = current_node.right
      end
    end

    self
  end

  def lookup(value)
    return nil if @root.nil?

    current_node = @root

    until current_node.nil?
      if value < current_node.value
        current_node = current_node.left
      elsif value > current_node.value
        current_node = current_node.right
      else
        return current_node
      end
    end

    nil
  end

  def remove(value)
    return false if @root.nil?

    current_node = @root
    parent_node = nil

    while current_node
      if value < current_node.value
        parent_node = current_node
        current_node = current_node.left
      elsif value > current_node.value
        parent_node = current_node
        current_node = current_node.right
      elsif current_node.value == value
        # We have a match, get to work!

        if current_node.right.nil?
          update_parent_link(parent_node, current_node, current_node.left)
        elsif current_node.right.left.nil?
          current_node.right.left = current_node.left
          update_parent_link(parent_node, current_node, current_node.right)
        else
          leftmost, leftmost_parent = find_leftmost(current_node.right)
          leftmost_parent.left = leftmost.right
          leftmost.left = current_node.left
          leftmost.right = current_node.right
          update_parent_link(parent_node, current_node, leftmost)
        end

        return true
      end
    end

    false
  end

  def traverse(node = @root)
    return nil if node.nil?

    tree = { value: node.value }
    tree[:left] = traverse(node.left)
    tree[:right] = traverse(node.right)

    tree
  end

  private

  def update_parent_link(parent_node, current_node, new_node)
    if parent_node.nil?
      @root = new_node
    elsif current_node.value < parent_node.value
      parent_node.left = new_node
    else
      parent_node.right = new_node
    end
  end

  def find_leftmost(node)
    leftmost = node.left
    leftmost_parent = node

    while leftmost.left
      leftmost_parent = leftmost
      leftmost = leftmost.left
    end

    [leftmost, leftmost_parent]
  end
end

RSpec.describe BinarySearchTree do
  let(:bst) { BinarySearchTree.new }

  before(:each) do
    # Construct the following tree:
    #
    #             9
    #       4           20
    #    1     6     15     170
    #
    bst.insert(9)
    bst.insert(4)
    bst.insert(6)
    bst.insert(20)
    bst.insert(170)
    bst.insert(15)
    bst.insert(1)
  end

  describe "#insert" do
    it "adds a value to the tree" do
      expect(bst.traverse).to eq({ value: 9,
                                   left: { value: 4,
                                           left: { value: 1, left: nil, right: nil },
                                           right: { value: 6, left: nil, right: nil } },
                                   right: { value: 20, left: { value: 15, left: nil, right: nil },
                                            right: { value: 170, left: nil, right: nil } } })
    end
  end

  describe "#lookup" do
    it "finds a value in the tree" do
      node = bst.lookup(15)
      expect(node.value).to eq(15)
    end

    it "returns nil for a value not in the tree" do
      node = bst.lookup(100)
      expect(node).to be_nil
    end
  end

  describe "#remove" do
    it "removes a leaf node" do
      expect(bst.remove(1)).to be true

      expect(bst.traverse).to eq({ value: 9,
                                   left: { value: 4, left: nil,
                                           right: { value: 6, left: nil, right: nil } },
                                   right: { value: 20, left: { value: 15, left: nil, right: nil },
                                            right: { value: 170, left: nil, right: nil } } })
    end

    it "removes a node with one child" do
      expect(bst.remove(20)).to be true

      expect(bst.traverse).to eq({ value: 9,
                                   left: { value: 4, left: { value: 1, left: nil, right: nil },
                                           right: { value: 6, left: nil, right: nil } },
                                   right: { value: 170, left: { value: 15, left: nil, right: nil },
                                            right: nil } })
    end

    it "removes a node with two children" do
      expect(bst.remove(4)).to be true

      expect(bst.traverse).to eq({ value: 9,
                                   left: { value: 6, left: { value: 1, left: nil, right: nil },
                                           right: nil },
                                   right: { value: 20, left: { value: 15, left: nil, right: nil },
                                            right: { value: 170, left: nil, right: nil } } })
    end

    it "returns false for a value not in the tree" do
      expect(bst.remove(100)).to be false
    end
  end
end
