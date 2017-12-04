
def busca_sequencial(valor, vetor)
    # Percorre todos os valores do vetor
    # ate encontrar o valor desejado
    for indice in 0..vetor.length-1
      if vetor[indice] == valor
          return indice
      end
    end
	return -1
end

vetor = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts busca_sequencial(98, vetor)