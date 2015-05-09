# Exemplo de Pilha em Python

import random

pilha = []

def insereValor(valor, pilha):
	pilha.append(valor)

def buscaSentinela(chave, pilha):
	pilha.append(chave)
	i = 0
	while pilha[i] != chave:
		i += 1
	if i == len(pilha)-1:
		pilha.pop()
		return -1
	pilha.pop()
	return i

def deletaValor(pilha):
	pilha.pop()

def mostraLista(pilha):
	print pilha

for x in xrange(0, 10):
	insereValor( random.randint(10,99) , pilha)

print 'Valor 25 na posicao: ' + str(buscaSentinela(25, pilha))

mostraLista(pilha)
deletaValor(pilha)
mostraLista(pilha)
deletaValor(pilha)
mostraLista(pilha)
deletaValor(pilha)
mostraLista(pilha)
insereValor( random.randint(10,99) , pilha)
mostraLista(pilha)
insereValor( random.randint(10,99) , pilha)
mostraLista(pilha)
insereValor( random.randint(10,99) , pilha)
mostraLista(pilha)