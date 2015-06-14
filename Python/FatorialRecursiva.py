def Fatorial(nro):
	if nro == 1:
		return 1
	else:
		return nro * Fatorial(nro-1)

print Fatorial(5)