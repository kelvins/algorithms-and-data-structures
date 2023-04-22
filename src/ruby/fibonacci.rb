# frozen_string_literal: true

def fibonacci(number)
  last = 0
  curr = 1
  (0..number - 1).each do |_|
    swap = curr
    curr += last
    last = swap
  end
  last
end

def fibonacci_recursiva(number)
  if number <= 0
    0
  elsif number == 1
    1
  else
    fibonacci(number - 1) + fibonacci(number - 2)
  end
end

puts fibonacci(12)
puts fibonacci_recursiva(12)
