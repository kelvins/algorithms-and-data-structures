# Mínimo e Máximo de um array usando divide & conquer
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

import random


def getMinMax(min_value, max_value, vetor):
    vetor_max = vetor[min_value]
    vetor_min = vetor[min_value]

    # Se só tiver 1 elemento
    if min_value == max_value:
        return (vetor_max, vetor_min)

    # Se tiver 2 elementos
    elif max_value == min_value + 1:
        if vetor[min_value] > vetor[max_value]:
            vetor_max, vetor_min = vetor[min_value], vetor[max_value]
        else:
            vetor_max, vetor_min = vetor[max_value], vetor[min_value]

        return (vetor_max, vetor_min)

    else:
        mid_value = int((min_value + max_value) / 2)
        vetor_max1, vetor_min1 = getMinMax(min_value, mid_value, vetor)
        vetor_max2, vetor_min2 = getMinMax(mid_value + 1, max_value, vetor)

    return (max(vetor_max1, vetor_max2), min(vetor_min1, vetor_min2))


if __name__ == "__main__":
    vetor = [random.randrange(10, 100) for _ in range(0, 10)]
    print(vetor)

    max_value, min_value = getMinMax(0, len(vetor) - 1, vetor)

    print(f"Min DC: {min_value}")
    print(f"Max DC: {max_value}")
