""" Counting sort in Python """

import random


def counting_sort(arr):
    """ Finding the max element in the list """
    k = max(arr) + 1

    """ Initialing count array of len k with 0's """
    count = [0] * k

    """ Counts frequency of each element """
    for i in arr:
        count[i] += 1

    """ Updates count array to reflect the correct position of each element in the sorted list """
    for i in range(1, k):
        count[i] += count[i - 1]

    """ Initializing result list with 0's """
    result = [0] * len(arr)

    """ Fill result array with the sorted elements"""
    for i in reversed(arr):
        result[count[i] - 1] = i
        count[i] -= 1

    return result


""" Generate a list of n random integers """
n = 10
list = [random.randint(0, 100) for _ in range(n)]

""" Prints original, unsorted list"""
print(f"List: {list}")

""" Sorts list using counting sort algorithm """
sorted_list = counting_sort(list)

""" Prints sorted list """
print(f"Sorted list: {sorted_list}")
