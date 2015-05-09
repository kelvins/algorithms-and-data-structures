# Exemplo de Fila em Python

import random

fila = []

def insereValor(valor, fila):
	fila.append(valor)

def buscaSentinela(chave, fila):
	fila.append(chave)
	i = 0
	while fila[i] != chave:
		i += 1
	if i == len(fila)-1:
		fila.pop()
		return -1
	fila.pop()
	return i

def deletaValor(fila):
	fila.pop(0)

def mostraLista(fila):
	print fila

for x in xrange(0, 10):
	insereValor( random.randint(10,99) , fila)

print 'Valor 25 na posicao: ' + str(buscaSentinela(25, fila))

mostraLista(fila)
deletaValor(fila)
mostraLista(fila)
deletaValor(fila)
mostraLista(fila)
deletaValor(fila)
mostraLista(fila)
insereValor( random.randint(10,99) , fila)
mostraLista(fila)
insereValor( random.randint(10,99) , fila)
mostraLista(fila)
insereValor( random.randint(10,99) , fila)
mostraLista(fila)