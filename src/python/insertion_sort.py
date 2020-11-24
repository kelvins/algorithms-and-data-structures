"""Implementação do algoritmo insertion sort iterativo e recursivo."""


def insertion_sort_iterativo(vetor):
    """
    Implementação do algoritmo de insertion sort iterativo.

    Args:
        vetor (list): lista que será ordenada.

    Returns:
        Retorna a lista ordenada.
    """
    for i in range(1, len(vetor)):
        chave = vetor[i]
        aux = i - 1
        while aux >= 0 and vetor[aux] > chave:
            vetor[aux + 1] = vetor[aux]
            aux -= 1
        vetor[aux + 1] = chave
    return vetor


def insertion_sort_recursivo(vetor, indice):
    """
    Implementação do algoritmo de insertion sort recursivo.

    Args:
        vetor (list): lista que será ordenada.
        indice (int): índice do elemento a ser ordenado na lista.

    Returns:
        Retorna a lista ordenada.
    """
    aux = indice
    while vetor[aux] < vetor[aux - 1]:
        temp = vetor[aux]
        vetor[aux] = vetor[aux - 1]
        vetor[aux - 1] = temp
        aux -= 1
        if aux == 0:
            break
    if indice < len(vetor) - 1:
        insertion_sort_recursivo(vetor, indice + 1)
    return vetor


if __name__ == '__main__':
    lista_nao_ordenada = [8, 1, 3, 5, 7, 9, 0, 2, 4, 6]
    print('Lista não ordenada:')
    print(lista_nao_ordenada)

    lista_nao_ordenada = insertion_sort_iterativo(lista_nao_ordenada)
    print('Lista ordenada com insertion sort iterativo:')
    print(lista_nao_ordenada)

    lista_nao_ordenada = insertion_sort_recursivo(lista_nao_ordenada, 1)
    print('Lista ordenada com insertion sort recursivo:')
    print(lista_nao_ordenada)
