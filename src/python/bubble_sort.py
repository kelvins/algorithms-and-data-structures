""" Implementation of the bubble sort algorithm with recursion """

def bubble_sort(data, size):
    """
    Implementation of a bubble sort algorithm with recursion.

    Arguments:
    date: list. List to be sorted
    size: int. List size

    Returns the ordered "date" list.
    """
    swap = False
    for i in range(0, size - 1):
        if data[i] > data[i + 1]:
            data[i], data[i + 1] = data[i + 1], data[i]
            swap = True
    if swap:
        bubble_sort(data, size - 1)


if __name__ == "__main__":
    lista_nao_ordenada = [2, 9, 8, 0, 1, 3, 5, 4, 6, 7]
    print(lista_nao_ordenada)
    bubble_sort(lista_nao_ordenada, len(lista_nao_ordenada))
    print(lista_nao_ordenada)
