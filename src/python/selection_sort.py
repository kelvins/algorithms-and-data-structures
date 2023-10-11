"""Implementation of a selection sort algorithm with recursion."""

def selection_sort(arr, index):
    """
    Implementation of a selection sort algorithm with recursion.
    Args:
    arr (list): The list to be sorted.
    index (int): The index of the element to be sorted in the list.
    """
    if index >= len(arr) - 1:
        return

    # min_index holds the position of the smallest value relative to the index
    min_index = index

    for i in range(index + 1, len(arr)):
        if arr[i] < arr[min_index]:
            min_index = i

    temp = arr[index]
    arr[index] = arr[min_index]
    arr[min_index] = temp

    selection_sort(arr, index + 1)

unsorted_list = [82, 83, 92, 12, 23, 45, 64, 91, 73]

print(unsorted_list)
selection_sort(unsorted_list, 0)
print(unsorted_list)


