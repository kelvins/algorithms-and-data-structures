# Lista Sequencial Dinamica e Ordenada

import random

lista = []

def inserirLista(chave, lista):
	lista.append(chave)
	i = 0
	while lista[i] < chave:
		i += 1
	p = len(lista)-2
	while p >= i:
		lista[p+1] = lista[p]
		p -= 1
	lista[i] = chave

def buscaSentinela(chave, lista):
	lista.append(chave)
	i = 0
	while lista[i] != chave:
		i += 1
	if i == len(lista)-1:
		lista.pop()
		return -1
	lista.pop()
	return i

def deletaValor(chave, lista):
	posicao = buscaSentinela(chave, lista)
	if posicao >= 0:
		lista.pop(posicao)
		return True
	else:
		return False

def mostraLista(lista):
	print lista

for x in xrange(0, 50):
	inserirLista( random.randint(10,99) , lista)

print 'Valor na posicao: ' + str(buscaSentinela(25, lista))

mostraLista(lista)
deletaValor(10, lista)
mostraLista(lista)