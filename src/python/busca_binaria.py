""" Implementation of the binary search algorithm with recursion """


def busca_binaria(valor, vetor, esquerda, direita):
    """
    Arguments:
    value: Any. Value to be searched in the list.
    vector: list. Ordered list in which the value will be searched.
    left: Any. Initial value of the searched half.
    right: Any. Final value of the searched half.

    Returns the index of the value in "vector" or -1 if it does not exist."

    """

    meio = int((esquerda + direita) / 2)

    if esquerda <= direita:
        if valor > vetor[meio]:
            esquerda = meio + 1
            return busca_binaria(valor, vetor, esquerda, direita)
        elif valor < vetor[meio]:
            direita = meio - 1
            return busca_binaria(valor, vetor, esquerda, direita)
        return meio
    return -1


lista = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print(busca_binaria(12, lista, 0, len(lista) - 1))
