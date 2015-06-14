def BubbleSort(vetor, tamanho):
	trocas = 0
	for x in xrange(0, tamanho-1):
		if vetor[x] > vetor[x+1]:
			temp = vetor[x]
			vetor[x] = vetor[x+1]
			vetor[x+1] = temp
			trocas = 1
	if trocas != 0:
		BubbleSort(vetor, tamanho-1)
	return vetor

vetor = [2, 9, 8, 0, 1, 3, 5, 4, 6, 7]
print vetor
vetor = BubbleSort(vetor, len(vetor))
print vetor