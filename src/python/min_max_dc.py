# Minimum and maximum of an array using divide and conquer

import random


def min_max_dc(array, start, end):
    """Encontra o value minimum e maximum em um array usando D&C."""
    if start == end:
        return array[start], array[start]

    middle = (start + end) // 2
    array_min1, array_max1 = min_max_dc(array, start, middle)
    array_min2, array_max2 = min_max_dc(array, middle + 1, end)
    return min(array_min1, array_min2), max(array_max1, array_max2)


if __name__ == "__main__":
    array = [random.randrange(10, 100) for _ in range(0, 10)]
    print(array)

    minimum, maximum = min_max_dc(array, 0, len(array) - 1)

    print(f"Min DC: {minimum}")
    print(f"Max DC: {maximum}")
