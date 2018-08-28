def exponenciacao(base, expoente)
  result = base
  expoente.pred.times { result *= base }
  result
end

# Teste Manual
puts exponenciacao(5, 2)
puts exponenciacao(5, 5)

# Teste Automatizado
require_relative 'ExponenciacaoTest'
