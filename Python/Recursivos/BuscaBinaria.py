def BuscaBinaria(valor, vetor, esquerda, direita):
	meio = int((esquerda+direita)/2)

	if esquerda <= direita:

		if valor > vetor[meio]:
			esquerda = meio + 1
			return BuscaBinaria(valor, vetor, esquerda, direita)
		elif valor < vetor[meio]:
			direita = meio - 1
			return BuscaBinaria(valor, vetor, esquerda, direita)
		else:
			return meio
			
	else:
		return -1 # Retorna -1 se o valor nao foi encontrado


vetor = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
# Parametros, valor que quer procurar, vetor, comeco e fim do vetor
print BuscaBinaria(12, vetor, 0, len(vetor)) # Se encontrar retorna a posicao do valor no vetor, senao retorna -1