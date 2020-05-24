""" Uma implementação simples de um algoritmo fatorial """


def fatorial(num):
    """
    Uma implementação simples de um algoritmo de fatorial.

    Argumentos:
        num: int. o número do qual deseja-se obter o fatorial.

    Retorna o resultado da operação.
    """
    aux = 1
    for i in range(2, num + 1):
        aux = aux * i
    return aux


if __name__ == '__main__':
    print(fatorial(5))
