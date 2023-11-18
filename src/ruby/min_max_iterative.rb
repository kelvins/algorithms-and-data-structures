# frozen_string_literal: true

# Mínimo e Máximo Interativo em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def min_max_array(vetor)
  minimo = vetor[0]
  maximo = vetor[0]

  vetor_size = vetor.length - 1
  (1..vetor_size).each do |i|
    if vetor[i] < minimo
      minimo = vetor[i]
    elsif vetor[i] > maximo
      maximo = vetor[i]
    end
  end

  puts "Minimo: #{minimo}"
  puts "Maximo: #{maximo}"
end

lista = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(lista)
