"""Implementação do algoritmo de máximo e mínimo com recursão"""


def max_min(array, minimo, maximo, index):
    """
    Imprime os values máximo e mínimo de um array
    """
    if array[index] < minimo:
        minimo = array[index]
    if array[index] > maximo:
        maximo = array[index]
    if index < len(array) - 1:
        max_min(array, minimo, maximo, index + 1)
    else:
        print(minimo)
        print(maximo)


um_vetor = [2, 94, 83, 10, 0, 2, 48, 1, 24]
max_min(um_vetor, um_vetor[0], um_vetor[0], 0)
