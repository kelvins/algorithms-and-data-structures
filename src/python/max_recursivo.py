# Exemplos de funções para achar maior número de um vetor
# Os 2 métodos são recursivos, porém apenas a MaxDC utiliza divisão e conquista
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

import random
from functools import reduce

# Maximo usando Divisão e Conquista


def max_dc(vetor, left, right):
    if left == right:
        return vetor[left]

    mid = int((left + right) / 2)

    max_1 = max_dc(vetor, left, mid)
    max_2 = max_dc(vetor, mid+1, right)

    return max_1 if max_1 > max_2 else max_2


def max_1(vetor, maximo, indice):
    if vetor[indice] > maximo:
        maximo = vetor[indice]

    if indice < len(vetor) - 1:
        max_1(vetor, maximo, indice+1)
    else:
        print(f"Max1: {maximo}")


if __name__ == "__main__":
    vetor = [0 for _ in range(0, 10)]

    for i in range(len(vetor)):
        vetor[i] = random.randrange(10, 100)

    print(vetor)

    max_1(vetor, vetor[0], 1)

    print(f"Max DC: {max_dc(vetor, 0, len(vetor)-1)}")

    print(f"Max Lambda: {max_dc(vetor, 0, len(vetor)-1)}")
