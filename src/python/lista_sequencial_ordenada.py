""" Lista Sequencial Dinamica e Ordenada """

import random

lista = []


def inserir_lista(chave, lista):
    """
    Insere a chave na lista
    """
    lista.append(chave)
    i, p = 0, 0
    while lista[i] < chave:
        i += 1
    p = len(lista) - 2
    while p >= i:
        lista[p + 1] = lista[p]
        p -= 1
    lista[i] = chave


def busca_sentinela(chave, lista):
    """ Algoritmo de busca sentinela """
    lista.append(chave)
    i = 0
    while lista[i] != chave:
        i += 1
    if i == len(lista) - 1:
        lista.pop()
        return -1
    lista.pop()
    return i


def deleta_valor(chave, lista):
    """ Deleta uma chave na lista """
    posicao = busca_sentinela(chave, lista)
    if posicao >= 0:
        lista.pop(posicao)
        return True
    return False


def mostra_lista(lista):
    """ Imprime a lista """
    print(lista)


for _ in range(0, 50):
    inserir_lista(random.randint(10, 99), lista)

print('Valor na posicao: ' + str(busca_sentinela(25, lista)))

mostra_lista(lista)
deleta_valor(10, lista)
mostra_lista(lista)
