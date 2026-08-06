# frozen_string_literal: true

def factorial(number)
  aux = 1
  (2..number).each do |x|
    aux *= x
  end
  aux
end

def recursive_factorial(number)
  return 1 if number <= 1

  number * recursive_factorial(number - 1)
end

puts factorial(5)
puts recursive_factorial(5)
