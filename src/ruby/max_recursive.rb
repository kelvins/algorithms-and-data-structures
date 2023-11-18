# frozen_string_literal: true

# Algoritmo de Máximo Recursivo em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def max_recursivo(vetor, maximo, indice)
  maximo = vetor[indice] if vetor[indice] > maximo

  maximo = max_recursivo(vetor, maximo, indice + 1) if indice < vetor.length - 1

  maximo
end

lista = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
print lista

puts "\nMaximo recursivo: #{max_recursivo(lista, lista[0], 0)}"
