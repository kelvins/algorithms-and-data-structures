# Mínimo e Máximo de um array usando divide & conquer
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

# Finding Minimum and Maximum of an array using divide & conquer
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

import random

def min_max_dc(array, start, end):
    """Finds the minimum and maximum values in an array using D&C."""
    if start == end:
        return array[start], array[start]

    middle = (start + end) // 2
    min1, max1 = min_max_dc(array, start, middle)
    min2, max2 = min_max_dc(array, middle + 1, end)
    return min(min1, min2), max(max1, max2)

if __name__ == "__main__":
    array = [random.randrange(10, 100) for _ in range(0, 10)]
    print(array)

    minimum, maximum = min_max_dc(array, 0, len(array) - 1)

    print(f"Min DC: {minimum}")
    print(f"Max DC: {maximum}")
