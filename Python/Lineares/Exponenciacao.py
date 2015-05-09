def Exponenciacao(base, expoente):
	for x in xrange(0, expoente-1):
		base = base * expoente
	return base

print Exponenciacao(5, 5)