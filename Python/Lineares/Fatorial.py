def Fatorial(num):
	aux = 1
	for x in xrange(2,num+1):
		aux = aux * x
	return aux

print Fatorial(5)