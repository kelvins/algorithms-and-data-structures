""" Implementation of the sequential search algorithm with recursion """

def sequential_search(value, list, index):
    """Recursive sequential search.

    Returns:
    Returns the index of the value in the list.
    If not found, returns -1.
    """
    if len(list) == 0 or index == len(list):
        return -1
    if list[index] == value:
        return index
    return sequential_search(value, list, index + 1)

if __name__ == "__main__":
    a_list = [1, 9, 39, 4, 12, 38, 94, 37]
    for index, value_in_list in enumerate(a_list):
        print("Testing value {} at index {}".format(value_in_list, index))
        assert sequential_search(value_in_list, a_list, 0) == index
