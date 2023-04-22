# frozen_string_literal: true

def BuscaBinaria(valor, vetor, esquerda, direita)
  meio = ((esquerda + direita) / 2).floor

  return -1 unless esquerda <= direita

  if valor > vetor[meio]
    esquerda = meio + 1
    BuscaBinaria(valor, vetor, esquerda, direita)
  elsif valor < vetor[meio]
    direita = meio - 1
    BuscaBinaria(valor, vetor, esquerda, direita)
  else
    meio
  end
end

vetor = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print BuscaBinaria(12, vetor, 0, vetor.length)
