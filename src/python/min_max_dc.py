# Minimum and maximum of an array using divide and conquer

import random


def min_max_dc(array, start, end):
    """Encontra o value mínimo e máximo em um array usando D&C."""
    if start == end:
        return array[start], array[start]

    meio = (start + end) // 2
    vetor_min1, vetor_max1 = min_max_dc(array, start, meio)
    vetor_min2, vetor_max2 = min_max_dc(array, meio + 1, end)
    return min(vetor_min1, vetor_min2), max(vetor_max1, vetor_max2)


if __name__ == "__main__":
    array = [random.randrange(10, 100) for _ in range(0, 10)]
    print(array)

    minimo, maximo = min_max_dc(array, 0, len(array) - 1)

    print(f"Min DC: {minimo}")
    print(f"Max DC: {maximo}")
