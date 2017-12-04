

def busca_sentinela(valor, vetor)
    # Adiciona o valor ao final do vetor
    vetor.push(valor)
    indice = 0
    
    # Enquanto nao for o valor, incrementa 1
    while vetor[indice] != valor
        indice += 1
    end
    
    # Remove o valor do final do vetor
    vetor.pop() 

    # Se a variavel indice corresponde ao tamanho do vetor, retorne -1
    if indice == vetor.length
        return -1
    end

    # Caso contrario, retorne a posicao do valor no vetor
    return indice
end

vetor = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts busca_sentinela(98, vetor)