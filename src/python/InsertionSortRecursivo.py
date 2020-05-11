def InsertionSort(vetor, indice):
	aux = indice
	while vetor[aux] < vetor[aux-1]:
		temp = vetor[aux]
		vetor[aux] = vetor[aux-1]
		vetor[aux-1] = temp
		aux -= 1
		if aux == 0:
			break
	if indice < len(vetor)-1:
		InsertionSort(vetor, indice+1)
	return vetor

vetor = [8, 1, 3, 5, 7, 9, 0, 2, 4, 6]
print vetor
vetor = InsertionSort(vetor, 1)
print vetor