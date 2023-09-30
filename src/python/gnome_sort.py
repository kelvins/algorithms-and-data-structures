"""
Implementação do Gnome Sort ou Stupid Sort
"""
"""
Implementation of Gnome Sort or Stupid Sort
"""


def gnome_sort(lst):
    i = 0
    while i < len(lst):
        # If the position i is 0 or if the value at i is greater than or equal to its previous,
        # the gnome will simply move one step forward
        if i == 0 or lst[i] >= lst[i - 1]:
            i += 1
        # If the content at position i is less than or equal to its previous,
        # the gnome will swap the values and move one step back to validate the order
        else:
            lst[i], lst[i - 1] = lst[i - 1], lst[i]
            i -= 1

    return lst


def main():
    lst = [-1, 1, 0, -7, 7, -5, 5, 2, -2, 4, -4, 9, -9, -6, 6, -8, 8, -3, 3]
    # Print the unsorted list
    print(f"List before sorting: {lst}")
    lst = gnome_sort(lst)
    # Print the sorted list
    print(f"List after sorting with Gnome Sort: {lst}")


if __name__ == "__main__":
    main()
