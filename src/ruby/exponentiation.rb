# frozen_string_literal: true

def exponenciacao(base, expoente)
  result = base
  expoente.pred.times { result *= base }
  result
end

puts exponenciacao(5, 2)
puts exponenciacao(5, 5)
