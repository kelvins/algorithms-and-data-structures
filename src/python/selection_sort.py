"""Implement recursive selection sort."""


def selection_sort(array, index):
    """Sort the array recursively.

    Args:
        array: The list to sort.
        index: The index of the element to process next.

    Returns:
        The sorted list.
    """
    if index >= len(array) - 1:
        return -1

    # min_index stores the index of the smallest value
    min_index = index

    for i in range(index + 1, len(array)):
        if array[i] < array[min_index]:
            min_index = i

    temp = array[index]
    array[index] = array[min_index]
    array[min_index] = temp

    selection_sort(array, index + 1)

    return array


list_not_sorted = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print(list_not_sorted)
list_not_sorted = selection_sort(list_not_sorted, 0)
print(list_not_sorted)
