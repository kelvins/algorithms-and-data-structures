
"""Implementation of the sequential search algorithm with recursion."""


def sequential_search(value, lst, index):
    """Recursive sequential search.

    Returns:
    Returns the index of the value in the list.
    If not found, returns -1.
    """
    if len(lst) == 0 or index == len(lst):
        return -1
    if lst[index] == value:
        return index
    return sequential_search(value, lst, index + 1)


if __name__ == "__main__":
    a_list = [1, 9, 39, 4, 12, 38, 94, 37]
    for index, value_in_list in enumerate(a_list):
        print("Testing value {} at index {}".format(value_in_list, index))
        assert sequential_search(value_in_list, a_list, 0) == index
        