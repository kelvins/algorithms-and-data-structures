def BuscaSequencial(valor, vetor):
	posicao = -1
	for x in xrange(0, len(vetor)):
		if vetor[x] == valor:
			posicao = x
			break
	return posicao

vetor = [1, 4, 5, 2, 42, 534, 54, 98, 89, 78, 67]
print BuscaSequencial(98, vetor)