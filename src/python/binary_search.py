"""Recursive Binary Search Algorithm in Python"""


def binary_search(value, vector, left, right):
    """
    Implementation of a binary search algorithm with recursion.

    Arguments:
    value: Any. Value to be searched for in the list
    vector: List. Ordered list in which value will be searched for
    left: Any. Leftmost index for binary search
    right: Any. Rightmost index for binary search

    Returns the index of value in vector; returns -1 if value not found in vector
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
