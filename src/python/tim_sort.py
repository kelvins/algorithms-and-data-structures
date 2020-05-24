"""
Implementacao do algoritmo Timsort
Referencia: https://www.geeksforgeeks.org/timsort/
"""

RUN = 32


def insertion_sort(data, left, right):
    """
    Use insertion sort to sort the dataay from the left
    index to the right index which is of size atmost RUN.
    """
    for index in range(left + 1, right + 1):
        temp = data[index]
        prev_index = index - 1
        while prev_index >= left and data[prev_index] > temp:
            data[prev_index + 1] = data[prev_index]
            prev_index -= 1
        data[prev_index + 1] = temp


def merge_sort(data, left, mid, right):
    """Merge sort function responsible for merging the sorted runs."""
    # The data is splited in two parts
    left_len = mid - left + 1
    left_part = [data[left + i] for i in range(0, left_len)]

    right_len = right - mid
    right_part = [data[mid + 1 + i] for i in range(0, right_len)]

    left_index, right_index, data_index = 0, 0, left

    # After comparing, we merge those two lists in larger sub list
    while left_index < left_len and right_index < right_len:
        if left_part[left_index] <= right_part[right_index]:
            data[data_index] = left_part[left_index]
            left_index += 1
        else:
            data[data_index] = right_part[right_index]
            right_index += 1
        data_index += 1

    # Copy remaining elements from the left part
    while left_index < left_len:
        data[data_index] = left_part[left_index]
        data_index += 1
        left_index += 1

    # Copy remaining elements from the right part
    while right_index < right_len:
        data[data_index] = right_part[right_index]
        data_index += 1
        right_index += 1


def timsort(data):
    """Iterative Timsort algorithm."""
    data_size = len(data)

    # Sort individual sub lists of size RUN
    for i in range(0, data_size, RUN):
        insertion_sort(data, i, min((i + 31), (data_size - 1)))

    # Start merging from size RUN.
    # It will merge to form size 64, 128, 256 and so on
    size = RUN
    while size < data_size:
        for left in range(0, data_size, 2 * size):
            # Find ending point of left sub list
            # mid+1 is starting point of right sub dataay
            mid = left + size - 1
            right = min((left + 2 * size - 1), (data_size - 1))

            # Merge sub list data[left.....mid] &  data[mid+1....right]
            merge_sort(data, left, mid, right)

        # After every merge, we increase left by 2 * size
        size = 2 * size


if __name__ == '__main__':
    data_to_sort = [99, 15, 23, 0, -9, 1, 45, 2, 10, 15]
    print('Unsorted data: ', data_to_sort)
    timsort(data_to_sort)
    print('Sorted data: ', data_to_sort)
