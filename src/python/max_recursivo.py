# Exemplos de funções para achar maior número de um vetor
# Os 2 métodos são recursivos, porém apenas a MaxDC utiliza divisão e conquista
# Bruno Dantas de Paiva - 2021
# https://github.com/DantasB

import random

# Maximo usando Divisão e Conquista


def max_dc(vetor, left, right):
    if left == right:
        return vetor[left]

    mid = int((left + right) / 2)

    max_1 = max_dc(vetor, left, mid)
    max_2 = max_dc(vetor, mid+1, right)

    return max_1 if max_1 > max_2 else max_2


def max_recursive(vetor, maximo, indice) -> int:
    result = maximo
    if vetor[indice] > result:
        result = vetor[indice]

    if indice < len(vetor) - 1:
        max_recursive(vetor, result, indice+1)
    else:
        return result


if __name__ == "__main__":
    vetor = [random.randrange(10, 100) for _ in range(0, 10)]

    print(vetor)
    print(f"Max Recursive: {max_recursive(vetor, vetor[0], 1)}")
    print(f"Max DC: {max_dc(vetor, 0, len(vetor)-1)}")
