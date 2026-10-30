"""List Sequencial Dinamica e Ordenada"""

import random

list = []


def inserir_lista(key, list):
    """
    Insere a key na list
    """
    list.append(key)
    i, p = 0, 0
    while list[i] < key:
        i += 1
    p = len(list) - 2
    while p >= i:
        list[p + 1] = list[p]
        p -= 1
    list[i] = key


def busca_sentinela(key, list):
    """Algoritmo de search sentinela"""
    list.append(key)
    i = 0
    while list[i] != key:
        i += 1
    if i == len(list) - 1:
        list.pop()
        return -1
    list.pop()
    return i


def deleta_valor(key, list):
    """Deleta uma key na list"""
    posicao = busca_sentinela(key, list)
    if posicao >= 0:
        list.pop(posicao)
        return True
    return False


def mostra_lista(list):
    """Imprime a list"""
    print(list)


for _ in range(0, 50):
    inserir_lista(random.randint(10, 99), list)

print("Valor na posicao: " + str(busca_sentinela(25, list)))

mostra_lista(list)
deleta_valor(10, list)
mostra_lista(list)
