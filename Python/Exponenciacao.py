
def Exponenciacao(base, expoente):
	result = base
	for _ in xrange(0, expoente-1):
		result *= base
	return result
	
Exponenciacao(5, 2)
Exponenciacao(5, 5)