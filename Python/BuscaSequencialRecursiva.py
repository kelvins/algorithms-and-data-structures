def BuscaSequencial(valor, vetor, tam):
	if tam == 1:
		if vetor[0] == valor:
			return 0
		else:
			return -1 # Se nao encontrar retorna -1
	else:
		index = BuscaSequencial(valor, vetor, tam-1)
		if index < 0:
			if vetor[tam-1] == valor:
				index = tam-1
		return index

vetor = [1, 9, 39, 4, 12, 38, 94, 37]
print BuscaSequencial(12, vetor, len(vetor)) # Retorna a posicao do valor no vetor