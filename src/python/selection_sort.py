"""Implementação de um algoritmo de selection sort com recursão"""


def selection_sort(array, index):
    """
    Implementação de um algoritmo de selection sort com recursão.

    Argumentos:
    array: list. List que será ordenada
    index: int. Indice do element a ser ordenado na list

    Retorna a list "array" ordenada.
    """
    if index >= len(array) - 1:
        return -1

    # minIndice stores the index of the smallest value
    min_indice = index

    for i in range(index + 1, len(array)):
        if array[i] < array[min_indice]:
            min_indice = i

    temp = array[index]
    array[index] = array[min_indice]
    array[min_indice] = temp

    selection_sort(array, index + 1)

    return array


lista_nao_ordenada = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print(lista_nao_ordenada)
lista_nao_ordenada = selection_sort(lista_nao_ordenada, 0)
print(lista_nao_ordenada)
