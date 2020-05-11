# Exemplo de Maximo, utilizando recursao e divisao e conquista
def MaxDC(vetor, inicio, fim):
	if inicio == fim:
		return vetor[inicio]
	meio = int( (inicio+fim)/2 )
	aux1 = MaxDC(vetor, inicio, meio)
	aux2 = MaxDC(vetor, meio+1, fim)
	if aux1 > aux2:
		return aux1
	else:
		return aux2

vetor = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
print vetor
print '\nMax:' + str( MaxDC(vetor, 0, len(vetor)-1) )