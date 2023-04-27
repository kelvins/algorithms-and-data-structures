""" Algoritmo de exponenciação implementado com recursão. """


def exponenciacao_recursiva(base, expoente):
    """Implementação de um algoritmo de exponenciação.

    Args:
        base (int): Base da operação
        expoente (int): Expoente da operação

    Returns:
        Retorna o resultado da operaçao de exponenciação.
    """
    if expoente == 0:
        return 1

    return base * exponenciacao_recursiva(base, expoente - 1)


if __name__ == "__main__":
    print(exponenciacao_recursiva(5, 2))
    print(exponenciacao_recursiva(5, 5))
