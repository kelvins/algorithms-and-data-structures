def exponenciacao(base, expoente)
  return 1 if expoente.zero?
  base * exponenciacao(base, expoente.pred)
end

# Teste Manual
puts exponenciacao(5, 2)
puts exponenciacao(5, 5)

# Teste Autmatizado
require_relative 'ExponenciacaoTest'
