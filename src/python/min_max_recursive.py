"""Implementação do algoritmo de maximum e minimum com recursão"""


def max_min(array, minimum, maximum, index):
    """
    Imprime os values maximum e minimum de um array
    """
    if array[index] < minimum:
        minimum = array[index]
    if array[index] > maximum:
        maximum = array[index]
    if index < len(array) - 1:
        max_min(array, minimum, maximum, index + 1)
    else:
        print(minimum)
        print(maximum)


um_array = [2, 94, 83, 10, 0, 2, 48, 1, 24]
max_min(um_array, um_array[0], um_array[0], 0)
