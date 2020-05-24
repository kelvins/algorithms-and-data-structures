""" Implementação do algoritmo insertion sort iterativo """

def insertion_sort(vetor):
    """
    Implementação de um algoritmo de insertion sort.

    Argumentos:
    vetor: lista. Lista que será ordenada

    Retorna a lista "vetor" ordenada
    """
    for i in range(1, len(vetor)):
        chave = vetor[i]
        aux = i-1
        while aux >= 0 and vetor[aux] > chave:
            vetor[aux+1] = vetor[aux]
            aux -= 1
        vetor[aux+1] = chave
    return vetor

lista_nao_ordenada = [92, 23, 42, 12, 54, 65, 1, 2, 8, 9, 31, 99]
print(insertion_sort(lista_nao_ordenada))
