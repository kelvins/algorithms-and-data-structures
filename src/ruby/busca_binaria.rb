# frozen_string_literal: true

def busca_binaria(valor, vetor, esquerda, direita)
  meio = ((esquerda + direita) / 2).floor

  return -1 unless esquerda <= direita

  if valor > vetor[meio]
    busca_binaria(valor, vetor, meio + 1, direita)
  elsif valor < vetor[meio]
    busca_binaria(valor, vetor, esquerda, meio - 1)
  else
    meio
  end
end

vetor = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print busca_binaria(12, vetor, 0, vetor.length)
