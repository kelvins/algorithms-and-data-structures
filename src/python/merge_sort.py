""" Merge sort algorithm implementation """


def merge_sort(data):
    """
    Sorts a list (data) in-place using merge sort approach.
    Args:
        data (list): unsorted list.
    """
    if len(data) < 2:
        return
    mid = len(data) // 2

    left_data = data[:mid]
    right_data = data[mid:]

    merge_sort(left_data)
    merge_sort(right_data)

    left_index = 0
    right_index = 0
    data_index = 0

    while left_index < len(left_data) and right_index < len(right_data):
        if left_data[left_index] < right_data[right_index]:
            data[data_index] = left_data[left_index]
            left_index += 1
        else:
            data[data_index] = right_data[right_index]
            right_index += 1
        data_index += 1

    while left_index < len(left_data):
        data[data_index] = left_data[left_index]
        left_index += 1
        data_index += 1

    while right_index < len(right_data):
        data[data_index] = right_data[right_index]
        right_index += 1
        data_index += 1


if __name__ == '__main__':
    some_list = [9, 1, 7, 6, 2, 8, 5, 3, 4, 0]
    print('Unsorted list: {}'.format(some_list))
    merge_sort(some_list)
    print('Sorted list: {}'.format(some_list))
