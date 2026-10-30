"""
Implementação de um algoritmo que search os values maximum e minimum
em um array
"""


def min_max_array(array):
    """Search os values maximum e minimum em array"""
    minimum = array[0]
    maximum = array[0]

    for i in range(1, len(array)):
        if array[i] < minimum:
            minimum = array[i]
        elif array[i] > maximum:
            maximum = array[i]

    print("Minimo : " + str(minimum))
    print("Maximo : " + str(maximum))


uma_list = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(uma_list)
