# Counting sort algorithm in Python
# Vinicios Barbosa da Silva - 2023
# https://github.com/ViniciosB

import random

def counting_sort(arr):
    # Find the maximum element in the list
    k = max(arr) + 1

    # Initialize the counting array with zeros
    count = [0] * k

    # Count the frequency of each element
    for i in arr:
        count[i] += 1

    # Update the counting array to reflect the correct position of each element in the sorted list
    for i in range(1, k):
        count[i] += count[i - 1]

    # Initialize the result array with zeros
    result = [0] * len(arr)

    # Fill the result array with the sorted elements
    for i in reversed(arr):
        result[count[i] - 1] = i
        count[i] -= 1

    return result

# Generate a list of n random numbers
n = 10
lista = [random.randint(0, 100) for _ in range(n)]

# Print the original unsorted list
print(f"Original List: {lista}")

# Sort the list using the Counting Sort algorithm
sorted_list = counting_sort(lista)

# Print the sorted list
print(f"Sorted List: {sorted_list}")
