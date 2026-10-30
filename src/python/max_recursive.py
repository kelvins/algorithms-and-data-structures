"""Find the maximum value recursively."""


def max_recursive(array, maximum, index):
    """Find the maximum value in the array using recursion."""
    if array[index] > maximum:
        maximum = array[index]
    if index < len(array) - 1:
        maximum = max_recursive(array, maximum, index + 1)
    return maximum


if __name__ == "__main__":
    values = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
    print(values)
    print(f"Max: {max_recursive(values, values[0], 0)}")
