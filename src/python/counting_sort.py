# Algoritmo de ordenação Counting sort em Python
# Vinicios Barbosa da Silva - 2023
# https://github.com/ViniciosB

import random

def counting_sort(arr):
    # Encontra o maior elemento na lista
    k = max(arr) + 1

    # Inicializa o array de contagem com zeros
    count = [0] * k

    # Conta a frequência de cada elemento
    for i in arr:
        count[i] += 1

    # Atualiza o array de contagem para refletir a posição correta de cada elemento na lista ordenada
    for i in range(1, k):
        count[i] += count[i-1]

    # Inicializa o array de resultado com zeros
    result = [0] * len(arr)

    # Preenche o array de resultado com os elementos ordenados
    for i in reversed(arr):
        result[count[i]-1] = i
        count[i] -= 1

    return result

# Gera uma lista de n números aleatórios
n = 10
lista = [random.randint(0, 100) for _ in range(n)]

# Imprime a lista original sem ordenação
print(f'Lista Original: {lista}')

# Ordena a lista utilizando o algoritmo de Counting Sort
lista_ordenada = counting_sort(lista)

# Imprime a lista ordenada
print(f'Lista Ordenada: {lista_ordenada}')
