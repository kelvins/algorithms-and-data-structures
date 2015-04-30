def SelectionSort(vetor, indice):
	
	if indice >= len(vetor)-1:
		return -1

	minIndice = indice # minIndice vai guardar posicao onde esta o menor valor em relacao ao indice
	
	for x in xrange(indice+1, len(vetor)):
		if vetor[x] < vetor[minIndice]:
			minIndice = x
	
	temp = vetor[indice]
	vetor[indice] = vetor[minIndice]
	vetor[minIndice] = temp
	
	SelectionSort(vetor, indice+1)
	
	return vetor

vetor = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print vetor
vetor = SelectionSort(vetor, 0)
print vetor
