# frozen_string_literal: true

# Implement the Stack data structure
class Stack
  def initialize
    @stack = []
  end

  def push(value)
    @stack.push(value)
  end

  def pop
    @stack.pop
  end

  def display
    print "#{@stack}\n"
  end
end

s = Stack.new

s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.display

s.pop
s.pop
s.display
