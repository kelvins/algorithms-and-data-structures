def InsertionSort(vetor):
	for x in range(1, len(vetor)):
		chave = vetor[x]
		aux = x-1
		while aux >= 0 and vetor[aux] > chave:
			vetor[aux+1] = vetor[aux]
			aux -= 1
		vetor[aux+1] = chave
	return vetor

vetor = [92, 23, 42, 12, 54, 65, 1, 2, 8, 9, 31, 99]
print InsertionSort(vetor)