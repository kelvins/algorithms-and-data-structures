"""Bucket Sort in Python"""


def bucket_sort(vector):
    """
    Implementation of bucket sort.

    Args:
        vector (list): list to be sorted.

    Returns:
        list: Returns the sorted list.

    Example:
    >>> bucket_sort([0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434])
    [0.1234, 0.3434, 0.565, 0.656, 0.665, 0.897]
    """
    if len(vector) == 0:
        return vector

    # Create empty buckets
    bucket_count = len(vector)
    max_val = max(vector)
    min_val = min(vector)

    # Range of each bucket
    bucket_range = (max_val - min_val) / bucket_count
    if bucket_range == 0:
        return vector

    buckets = [[] for _ in range(bucket_count + 1)]

    # Put elements into buckets
    for i in range(len(vector)):
        diff = (vector[i] - min_val) / bucket_range
        index = int(diff)
        buckets[index].append(vector[i])

    # Sort individual buckets and concatenate
    sorted_vector = []
    for i in range(len(buckets)):
        # Using insertion sort for each bucket
        buckets[i] = insertion_sort(buckets[i])
        for j in range(len(buckets[i])):
            sorted_vector.append(buckets[i][j])

    return sorted_vector


def insertion_sort(vector):
    """
    Implementation of insertion sort for use within bucket sort.

    Args:
        vector (list): list to be sorted.

    Returns:
        list: Returns the sorted list.
    """
    for i in range(1, len(vector)):
        key = vector[i]
        aux = i - 1
        while aux >= 0 and vector[aux] > key:
            vector[aux + 1] = vector[aux]
            aux -= 1
        vector[aux + 1] = key
    return vector


if __name__ == "__main__":
    list1 = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
    print("Unsorted list: ", list1)

    sorted_list = bucket_sort(list1)
    print("Sorted list with bucket sort: ", sorted_list)
