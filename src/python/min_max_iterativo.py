"""
Implementação de um algoritmo que busca os valores máximo e mínimo
em um array
"""


def min_max_array(vetor):
    """ Busca os valores máximo e mínimo em vetor """
    minimo = vetor[0]
    maximo = vetor[0]

    for i in range(1, len(vetor)):
        if vetor[i] < minimo:
            minimo = vetor[i]
        elif vetor[i] > maximo:
            maximo = vetor[i]

    print('Minimo : ' + str(minimo))
    print('Maximo : ' + str(maximo))


uma_lista = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(uma_lista)
