""" Implementação de um algoritmo de selection sort com recursão """


def selection_sort(vetor, indice):
    """
    Implementação de um algoritmo de selection sort com recursão.

    Argumentos:
    vetor: lista. Lista que será ordenada
    indice: int. Indice do elemento a ser ordenado na lista

    Retorna a lista "vetor" ordenada.
    """
    if indice >= len(vetor) - 1:
        return -1

    # minIndice guarda a posicao onde esta o menor valor em relacao ao indice
    min_indice = indice

    for i in range(indice + 1, len(vetor)):
        if vetor[i] < vetor[min_indice]:
            min_indice = i

    temp = vetor[indice]
    vetor[indice] = vetor[min_indice]
    vetor[min_indice] = temp

    selection_sort(vetor, indice + 1)

    return vetor


lista_nao_ordenada = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print(lista_nao_ordenada)
lista_nao_ordenada = selection_sort(lista_nao_ordenada, 0)
print(lista_nao_ordenada)
