"""
Implementação do Gnome Sort ou Stupid Sort
"""


def gnomesort(list):
    i = 0
    while i < len(list):
        # If i is 0 or its value is greater than or equal
        # to the previous value, the gnome moves forward one position
        if i == 0 or list[i] >= list[i - 1]:
            i += 1

        # If the value at position i is less than or equal to the previous value,
        # the gnome swaps them and moves back one position
        # to check the order again
        else:
            list[i], list[i - 1] = list[i - 1], list[i]
            i -= 1

    return list


def main():
    list = [-1, 1, 0, -7, 7, -5, 5, 2, -2, 4, -4, 9, -9, -6, 6, -8, 8, -3, 3]
    # Print the unsorted list
    print(f"List antes de ser sorted: {list}")
    list = gnomesort(list)
    # Print the sorted list
    print(f"List após sortção com Gnome Sort: {list}")


if __name__ == "__main__":
    main()
