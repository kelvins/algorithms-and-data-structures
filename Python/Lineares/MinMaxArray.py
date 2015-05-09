def MinMaxArray(vetor):
	minimo = vetor[0]
	maximo = vetor[0]

	for x in xrange(1, len(vetor)):
		if vetor[x] < minimo:
			minimo = vetor[x]
		elif vetor[x] > maximo:
			maximo = vetor[x]

	print 'Minimo : ' + str(minimo)
	print 'Maximo : ' + str(maximo)

vetor = [2, 94, 83, 10, 0, 2, 48, 1, 24]
MinMaxArray(vetor)