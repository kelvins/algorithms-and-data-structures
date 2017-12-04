
def Exponenciacao(base, expoente):
	if expoente == 0:
		return 1
	else:
		return base * Exponenciacao(base, expoente-1)

Exponenciacao(5, 2)
Exponenciacao(5, 5)