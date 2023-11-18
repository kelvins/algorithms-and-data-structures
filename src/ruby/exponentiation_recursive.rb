# frozen_string_literal: true

def exponenciacao(base, expoente)
  return 1 if expoente.zero?

  base * exponenciacao(base, expoente.pred)
end

puts exponenciacao(5, 2)
puts exponenciacao(5, 5)
