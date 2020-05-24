""" Heap sort algorithm implementation """


def heap_sort(data):
    """Sort a list (data) in-place using HeapSort.

    Args:
        data (list): lista to be sorted.
    """
    length = len(data)
    index = length // 2
    parent = 0
    child = 0
    temp = 0
    while True:
        if index > 0:
            index -= 1
            temp = data[index]
        else:
            length -= 1
            if length == 0:
                return
            temp = data[length]
            data[length] = data[0]

        parent = index
        child = index * 2 + 1

        while child < length:
            if (child + 1) < length and data[child + 1] > data[child]:
                child += 1
            if data[child] > temp:
                data[parent] = data[child]
                parent = child
                child = parent * 2 + 1
            else:
                break
        data[parent] = temp


if __name__ == '__main__':
    list_to_sort = [9, 1, 7, 6, 2, 8, 5, 3, 4, 0]
    print('Unsorted list: {}'.format(list_to_sort))
    heap_sort(list_to_sort)
    print('Sorted list: {}'.format(list_to_sort))
