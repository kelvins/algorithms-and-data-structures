# frozen_string_literal: true

def exponentiation(base, exponent)
  result = base
  exponent.pred.times { result *= base }
  result
end

puts exponentiation(5, 2)
puts exponentiation(5, 5)
