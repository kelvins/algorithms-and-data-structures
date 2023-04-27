# Busca por interpolação em Python
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB


def interpolation_search(array, x):
    """Executa a busca por interpolação

    Args:
        array (list): lista com os elementos
        x (int): elemento a ser encontrado

    Returns:
        int: posição do elemento
    """
    low = 0
    high = len(array) - 1

    array_low = array[low]
    array_high = array[high]

    while (low <= high) and (x >= array_low) and (x <= array_high):
        array_low = array[low]
        array_high = array[high]
        pos = (int)(low + ((high - low) / (array_high - array_low)) * (x - array_low))

        if array[pos] < x:
            low = pos + 1

        elif array[pos] > x:
            high = pos - 1

        else:
            return pos

    return -1


if __name__ == '__main__':
    array = [1, 4, 6, 23, 2, 9, 5, 78, 123, 5444, 54535, 64, 3, 0, 12, 14, 15, 31, 25]
    array.sort()

    element_to_be_found = 5444

    index = interpolation_search(array, element_to_be_found)

    if index != -1:
        print(f"Elemento encontrado no indice {index} do array ordenado.")
    else:
        print("Elemento não foi encontrado.")
