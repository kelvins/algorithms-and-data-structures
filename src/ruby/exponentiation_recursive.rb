# frozen_string_literal: true

def exponentiation(base, exponent)
  return 1 if exponent.zero?

  base * exponentiation(base, exponent.pred)
end

puts exponentiation(5, 2)
puts exponentiation(5, 5)
