def binary_search(value, array, left, right):
    """
    Implementation of a binary search algorithm with recursion.

    Arguments:
    value: Any. The value to be searched for in the list.
    array: list. The sorted list in which the value will be searched.
    left: Any. The initial value of the searched half.
    right: Any. The final value of the searched half.

    Returns the index of the value in "array" or -1 if it does not exist.
    """
    middle = int((left + right) / 2)

    if left <= right:
        if value > array[middle]:
            left = middle + 1
            return binary_search(value, array, left, right)
        elif value < array[middle]:
            right = middle - 1
            return binary_search(value, array, left, right)
        return middle
    return -1

array = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print(binary_search(12, array, 0, len(array) - 1))

