"""Implementação do algoritmo insertion sort iterativo e recursivo."""
"""Implementation of Iterative and Recursive Insertion Sort Algorithm."""

def insertion_sort_iterative(array):
    """
    Implementation of the iterative insertion sort algorithm.

    Args:
        array (list): List to be sorted.

    Returns:
        Returns the sorted list.
    """
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
    return array

def insertion_sort_recursive(array, index):
    """
    Implementation of the recursive insertion sort algorithm.

    Args:
        array (list): List to be sorted.
        index (int): Index of the element to be sorted in the list.

    Returns:
        Returns the sorted list.
    """
    current_index = index
    while array[current_index] < array[current_index - 1]:
        temp = array[current_index]
        array[current_index] = array[current_index - 1]
        array[current_index - 1] = temp
        current_index -= 1
        if current_index == 0:
            break
    if index < len(array) - 1:
        insertion_sort_recursive(array, index + 1)
    return array

if __name__ == "__main__":
    unsorted_list = [8, 1, 3, 5, 7, 9, 0, 2, 4, 6]
    print("Unsorted List:")
    print(unsorted_list)

    unsorted_list = insertion_sort_iterative(unsorted_list)
    print("Sorted List with Iterative Insertion Sort:")
    print(unsorted_list)

    unsorted_list = insertion_sort_recursive(unsorted_list, 1)
    print("Sorted List with Recursive Insertion Sort:")
    print(unsorted_list)
