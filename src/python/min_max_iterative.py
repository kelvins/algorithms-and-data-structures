"""Find the minimum and maximum values in an array iteratively."""


def min_max_array(array):
    """Find the minimum and maximum values in the array."""
    minimum = array[0]
    maximum = array[0]

    for i in range(1, len(array)):
        if array[i] < minimum:
            minimum = array[i]
        elif array[i] > maximum:
            maximum = array[i]

    print("Minimum: " + str(minimum))
    print("Maximum: " + str(maximum))


values = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(values)
