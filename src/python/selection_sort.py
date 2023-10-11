def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Example usage:
unsorted_list = [82, 83, 92, 12, 23, 45, 64, 91, 73]
print(unsorted_list)
selection_sort(unsorted_list)
print(unsorted_list)
