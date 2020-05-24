""" Algoritmo de exponenciação """


def exponenciacao(base, expoente):
    """
    Implementação de um algoritmo de exponenciação.

    Argumentos:
        base: int. Base da operação
        expoente: int. Expoente da operação.

    Retorna o resultado da operação de exponenciação
    """
    result = base
    for _ in range(0, expoente - 1):
        result *= base
    return result


print(exponenciacao(5, 2))
print(exponenciacao(5, 5))
