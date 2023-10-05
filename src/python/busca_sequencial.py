"""
Implementation of the sequential search and sentinel search algorithms.
"""


def sequential_search(value, array):
    """
    Implementation of a sequential search algorithm.

    Arguments:
    value: Any. The value to be searched in the list.
    array: list. The list in which the value will be searched.

    Returns the index of the value in "array" or -1 if it does not exist in the list.
    """
    for i in range(0, len(array)):
        if array[i] == value:
            return i
    return -1


def sentinel_search(value, array):
    """
    Implementation of a sentinel search algorithm.

    Arguments:
    value: Any. The value to be searched in the list.
    array: list. The list in which the value will be searched.

    Returns the index of the value in "array" or -1 if it does not exist in the list.
    """
    array.append(value)
    index = 0
    while array[index] != value:
        index += 1
    array.pop()
    if index == len(array) - 1:
        return -1
    return index


some_list = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
print(sequential_search(54, some_list))
print(sentinel_search(98, some_list))
