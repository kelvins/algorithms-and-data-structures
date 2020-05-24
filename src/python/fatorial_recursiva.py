""" Algoritmo de fatorial implementado com recursão """


def fatorial_recursivo(numero):
    """
    Implementação de um algoritmo de fatorial com recursão.

    Argumentos:
        numero: int. o número do qual deseja-se obter o fatorial.

    Retorna o resultado da operação.
    """
    if numero == 1:
        return 1

    return numero * fatorial_recursivo(numero - 1)


print(fatorial_recursivo(5))
