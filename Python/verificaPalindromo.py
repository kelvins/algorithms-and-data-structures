def verificaPalindromo(palavra):
	inicio=0
	fim=len(palavra)-1
	size = len(palavra)/2
	cont = 0
	for i in range(size):
		if palavra[inicio] == palavra[fim]:
			cont+=1
		inicio+=1;
		fim-=1;
		
			 
	if cont == size:
		return True
	else:
		return False
