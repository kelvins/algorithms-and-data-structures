"""Implement sequential and sentinel search algorithms."""


def sequential_search(value, array):
    """
    Perform sequential search.

    Args:
        value: The value to find.
        array: The list to search.

    Returns:
        The index of the value, or -1 if it is absent.
    """
    for i in range(0, len(array)):
        if array[i] == value:
            return i
    return -1


def sentinel_search(value, array):
    """
    Perform sentinel search.

    Args:
        value: The value to find.
        array: The list to search.

    Returns:
        The index of the value, or -1 if it is absent.
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
