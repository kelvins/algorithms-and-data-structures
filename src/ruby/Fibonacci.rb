# frozen_string_literal: true

def fibonacci(n)
  last = 0
  curr = 1
  (0..n - 1).each do |_|
    swap = curr
    curr += last
    last = swap
  end
  last
end

def fibonacci_recursiva(n)
  if n <= 0
    0
  elsif n == 1
    1
  else
    fibonacci(n - 1) + fibonacci(n - 2)
  end
end

puts fibonacci(12)
puts fibonacci_recursiva(12)
