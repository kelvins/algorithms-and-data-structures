def MaxMin(vetor, minimo, maximo, indice):
	if vetor[indice] < minimo:
		minimo = vetor[indice]
	if vetor[indice] > maximo:
		maximo = vetor[indice]
	if indice < len(vetor)-1:
		MaxMin(vetor, minimo, maximo, indice+1)
	else:
		print minimo
		print maximo
		
vetor = [2, 94, 83, 10, 0, 2, 48, 1, 24]
MaxMin(vetor, vetor[0], vetor[0], 0)