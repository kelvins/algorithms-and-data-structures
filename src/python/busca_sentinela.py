""" Implementation of the sentinel search algorithm """

def sentinel_search(list_to_search, value):
    """
    Implementation of a sentinel search algorithm.

    Arguments:
    value: Any. The value to be searched in the list.
    list_to_search: list. The list in which the value will be searched.

    Returns the index of the value in "list_to_search" or -1 if it does not exist in the list.
    """
    list_to_search.append(value)
    list_index = 0
    while list_to_search[list_index] != value:
        list_index = list_index + 1
    list_to_search.pop()
    if list_index == len(list_to_search):
        return -1
    return list_index

if __name__ == "__main__":
    some_list = [1, 9, 2, 8, 7, 4, 5, 6, 4, 3, 10, 0]
    NUMBER_TO_FIND = 4
    NUMBER_INDEX = sentinel_search(some_list, NUMBER_TO_FIND)
    print(some_list)
    if NUMBER_INDEX >= 0:
        print("Found value {} at position {}.".format(NUMBER_TO_FIND, NUMBER_INDEX))
    else:
        print("Could not find value {}.".format(NUMBER_TO_FIND))
