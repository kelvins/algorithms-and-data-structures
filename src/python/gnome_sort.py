"""
Implement the Gnome Sort (also known as Stupid Sort) algorithm.
"""


def gnomesort(values):
    i = 0
    while i < len(values):
        # If i is 0 or its value is greater than or equal
        # to the previous value, the gnome moves forward one position
        if i == 0 or values[i] >= values[i - 1]:
            i += 1

        # If the value at position i is less than or equal to the previous value,
        # the gnome swaps them and moves back one position
        # to check the order again
        else:
            values[i], values[i - 1] = values[i - 1], values[i]
            i -= 1

    return values


def main():
    values = [-1, 1, 0, -7, 7, -5, 5, 2, -2, 4, -4, 9, -9, -6, 6, -8, 8, -3, 3]
    # Print the unsorted list
    print(f"List before sorting: {values}")
    values = gnomesort(values)
    # Print the sorted list
    print(f"List after sorting with Gnome Sort: {values}")


if __name__ == "__main__":
    main()
