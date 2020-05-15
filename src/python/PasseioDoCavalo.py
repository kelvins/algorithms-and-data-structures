
def Aceitavel(x, y): # Aceitavel se estiver dentro do tabuleiro e a casa ainda nao tiver sido visitada - Retorna True ou False
	if x >= 0 and x <= num-1 and y >= 0 and y <= num-1 and tabuleiro[x][y] == 0:
		return True
	else:
		return False

def TentaMover(i, x, y): # Tenta o i-esimo movimento em (x,y), 1 <= i <= n^2
	done = i > numSqr # True ou False
	k = 0
	while done == False and k < 8:
		u = x + dx[k] # Coordenadas dos 8 movimentos possiveis do cavalo
		v = y + dy[k] # Coordenadas dos 8 movimentos possiveis do cavalo
		if Aceitavel(u, v):
			tabuleiro[u][v] = i
			done = TentaMover(i+1, u, v) # Tenta outro movimento
			if done == False:
				tabuleiro[u][v] = 0 # Sem sucesso, descarta movimento
		k += 1 # Passa ao proximo movimento possivel
	return done

def MostraMovimento(x, y):
	tabuleiro[x][y] = 1
	done = TentaMover(2, x, y)
	string = ""
	if done == True:
		for x in xrange(0, num):
			for y in xrange(0, num):
				if tabuleiro[x][y] < 10:
					string += "0" + str(tabuleiro[x][y]) + " "
				else:
					string += str(tabuleiro[x][y]) + " "
			string += "\n"
		print string
	else:
		print "Nao ha passeio possivel\n"

dx = [2, 1, -1, -2, -2, -1, 1, 2] # Para calculo das coordenadas dos movimentos possiveis do cavalo (8 movimentos possiveis)
dy = [1, 2, 2, 1, -1, -2, -2, -1] # Para calculo das coordenadas dos movimentos possiveis do cavalo (8 movimentos possiveis)

print "Digite o num de posicoes do tabuleiro: (ex.: 6) <= 10"
num = int(raw_input()) # Numero de posicoes do tabuleiro
print "Digite a posicao x onde o cavalo deve iniciar: (ex.: 1) >= 0"
x = int(raw_input()) # Numero de posicoes do tabuleiro
print "Digite a posicao y onde o cavalo deve iniciar: (ex.: 2) >= 0"
y = int(raw_input()) # Numero de posicoes do tabuleiro
numSqr = num * num # Numero total de casas

print

tabuleiro = [[],[],[],[],[],[],[],[],[],[]] # Tabuleiro maximo 20x20
for x in xrange(0, num):
	for y in xrange(0, num):
		tabuleiro[x].append(0)
#print tabuleiro
MostraMovimento(x, y)