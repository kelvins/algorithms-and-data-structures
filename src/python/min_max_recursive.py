""" Implementação do algoritmo de máximo e mínimo com recursão """


def max_min(vetor, minimo, maximo, indice):
    """
    Imprime os valores máximo e mínimo de um vetor
    """
    if vetor[indice] < minimo:
        minimo = vetor[indice]
    if vetor[indice] > maximo:
        maximo = vetor[indice]
    if indice < len(vetor) - 1:
        max_min(vetor, minimo, maximo, indice + 1)
    else:
        print(minimo)
        print(maximo)


um_vetor = [2, 94, 83, 10, 0, 2, 48, 1, 24]
max_min(um_vetor, um_vetor[0], um_vetor[0], 0)
