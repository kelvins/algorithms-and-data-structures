""" Implementação do algoritmo insertion sort com recursão """


def insertion_sort_recursivo(vetor, indice):
    """
    Implementação de um algoritmo de insertion sort com recursão.

    Argumentos:
    vetor: lista. Lista que será ordenada
    indice: int. Indice do elemento a ser ordenado na lista

    Retorna a lista "vetor" ordenada.
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


lista_nao_ordenada = [8, 1, 3, 5, 7, 9, 0, 2, 4, 6]
print(lista_nao_ordenada)
lista_nao_ordenada = insertion_sort_recursivo(lista_nao_ordenada, 1)
print(lista_nao_ordenada)
