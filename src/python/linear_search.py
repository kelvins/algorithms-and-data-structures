"""
Implementação dos algoritmos de busca sequencial e
busca sentinela
"""


def sequential_search(value, array):
    """
    Implementação de um algoritmo de busca sequencial.

    Argumentos:
    value: Any. Valor a ser buscado na lista
    array: list. lista na qual o valor será buscado

    Retorna o índice do valor em "array" ou -1 caso não exista nela.
    """
    for i in range(0, len(array)):
        if array[i] == value:
            return i
    return -1


def sentinel_search(value, array):
    """
    Implementação de um algoritmo de busca sentinela.

    Argumentos:
    value: Any. Valor a ser buscado na lista
    array: list. lista na qual o valor será buscado

    Retorna o índice do valor em "array" ou -1 caso não exista nela.
    """
    array.append(value)
    index = 0
    while array[index] != value:
        index += 1
    array.pop()
    if index == len(array) - 1:
        return -1
    return index


some_list = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
print(sequential_search(54, some_list))
print(sentinel_search(98, some_list))
