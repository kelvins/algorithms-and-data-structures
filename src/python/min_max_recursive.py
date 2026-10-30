"""Find an array's minimum and maximum values recursively."""


def max_min(array, minimum, maximum, index):
    """Print the minimum and maximum values in the array."""
    if array[index] < minimum:
        minimum = array[index]
    if array[index] > maximum:
        maximum = array[index]
    if index < len(array) - 1:
        max_min(array, minimum, maximum, index + 1)
    else:
        print(minimum)
        print(maximum)


array = [2, 94, 83, 10, 0, 2, 48, 1, 24]
max_min(array, array[0], array[0], 0)
