# frozen_string_literal: true

def busca_sequencial(valor, vetor)
  # Procura o valor no vetor sequencialmente
  # Se encontrar retorna o índice, senão -1
  vetor.each_with_index do |elemento, indice|
    return indice if elemento.equal?(valor)
  end
  -1
end

vetor = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts busca_sequencial(98, vetor)
