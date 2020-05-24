""" Algoritmo de exponenciação implementado com recursão """


def exponenciacao_recursiva(base, expoente):
    """
    Implementação de um algoritmo de exponenciação.

    Argumentos:
        base: int. Base da operação
        expoente: int. Expoente da operação

    Retorna o resultado da operaçao de exponenciação.
    """
    if expoente == 0:
        return 1

    return base * exponenciacao_recursiva(base, expoente - 1)


print(exponenciacao_recursiva(5, 2))
print(exponenciacao_recursiva(5, 5))
