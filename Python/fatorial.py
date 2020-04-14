def fatorial(num):
	aux = 1
	for x in range(2, num+1):
		aux = aux * x
	return aux


if __name__ == '__main__':
    print(fatorial(5))
