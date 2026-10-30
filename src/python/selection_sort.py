"""Implementação de um algoritmo de selection sort com recursão"""


def selection_sort(array, index):
    """
    Implementação de um algoritmo de selection sort com recursão.

    Argumentos:
    array: list. List que será sorted
    index: int. Indice do element a ser sorted na list

    Retorna a list "array" sorted.
    """
    if index >= len(array) - 1:
        return -1

    # minIndice stores the index of the smallest value
    min_index = index

    for i in range(index + 1, len(array)):
        if array[i] < array[min_index]:
            min_index = i

    temp = array[index]
    array[index] = array[min_index]
    array[min_index] = temp

    selection_sort(array, index + 1)

    return array


list_not_sorted = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print(list_not_sorted)
list_not_sorted = selection_sort(list_not_sorted, 0)
print(list_not_sorted)
