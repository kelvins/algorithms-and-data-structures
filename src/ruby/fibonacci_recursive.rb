# frozen_string_literal: true

def fibonacci_recursiva(number)
  if number <= 0
    0
  elsif number == 1
    1
  else
    fibonacci(number - 1) + fibonacci(number - 2)
  end
end

puts fibonacci_recursiva(12)
