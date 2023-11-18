# Mínimo e Máximo de um array usando divide & conquer

import random


def min_max_dc(vetor, inicio, fim):
    """Encontra o valor mínimo e máximo em um vetor usando D&C."""
    if inicio == fim:
        return vetor[inicio], vetor[inicio]

    meio = (inicio + fim) // 2
    vetor_min1, vetor_max1 = min_max_dc(vetor, inicio, meio)
    vetor_min2, vetor_max2 = min_max_dc(vetor, meio + 1, fim)
    return min(vetor_min1, vetor_min2), max(vetor_max1, vetor_max2)


if __name__ == "__main__":
    vetor = [random.randrange(10, 100) for _ in range(0, 10)]
    print(vetor)

    minimo, maximo = min_max_dc(vetor, 0, len(vetor) - 1)

    print(f"Min DC: {minimo}")
    print(f"Max DC: {maximo}")
