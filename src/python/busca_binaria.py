""" Implementation of the binary search algorithm with recursion """


def binary_search(value, vector, left, right):
    """
    Implementation of a binary search algorithm with recursion.

    Arguments:
    value: Any. Value to be searched for in the list
    vector: list. ordered list in which the value will be searched
    left: Any. Initial value of the half sought
    right: Any. Final value of the half sought

    Returns the index of the value in "vector" or -1 if it does not exist in it.
    """
    middle = int((left + right) / 2)

    if left <= right:
        if value > vector[middle]:
            left = middle + 1
            return binary_search(value, vector, left, right)
        elif value < vector[middle]:
            right = middle - 1
            return binary_search(value, vector, left, right)
        return middle
    return -1


list = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print(binary_search(12, list, 0, len(list) - 1))