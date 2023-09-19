def bubble_sort(data, size):
    """
    Implementation of a bubble sort algorithm with recursion.

    Arguments:
    data: list. The list to be sorted.
    size: int. The size of the list.

    Returns the sorted "data" list.
    """
    swap = False
    for i in range(0, size - 1):
        if data[i] > data[i + 1]:
            data[i], data[i + 1] = data[i + 1], data[i]
            swap = True
    if swap:
        bubble_sort(data, size - 1)


if __name__ == "__main__":
    unsorted_list = [2, 9, 8, 0, 1, 3, 5, 4, 6, 7]
    print(unsorted_list)
    bubble_sort(unsorted_list, len(unsorted_list))
    print(unsorted_list)

