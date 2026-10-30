"""
Implementação de um algoritmo que search os values máximo e mínimo
em um array
"""


def min_max_array(array):
    """Search os values máximo e mínimo em array"""
    minimo = array[0]
    maximo = array[0]

    for i in range(1, len(array)):
        if array[i] < minimo:
            minimo = array[i]
        elif array[i] > maximo:
            maximo = array[i]

    print("Minimo : " + str(minimo))
    print("Maximo : " + str(maximo))


uma_lista = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(uma_lista)
