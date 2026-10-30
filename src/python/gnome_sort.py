"""
Implementação do Gnome Sort ou Stupid Sort
"""


def gnomesort(lista):
    i = 0
    while i < len(lista):
        # If i is 0 or its value is greater than or equal
        # to the previous value, the gnome moves forward one position
        if i == 0 or lista[i] >= lista[i - 1]:
            i += 1

        # If the value at position i is less than or equal to the previous value,
        # the gnome swaps them and moves back one position
        # to check the order again
        else:
            lista[i], lista[i - 1] = lista[i - 1], lista[i]
            i -= 1

    return lista


def main():
    lista = [-1, 1, 0, -7, 7, -5, 5, 2, -2, 4, -4, 9, -9, -6, 6, -8, 8, -3, 3]
    # Print the unsorted list
    print(f"Lista antes de ser ordenada: {lista}")
    lista = gnomesort(lista)
    # Print the sorted list
    print(f"Lista após ordenação com Gnome Sort: {lista}")


if __name__ == "__main__":
    main()
