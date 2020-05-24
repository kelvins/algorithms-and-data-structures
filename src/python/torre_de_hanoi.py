""" Implementaçao do algoritmo Torre de Hanoi """


def hanoi(pino0, pino2, pino1, discos):
    """
    Mostra os passos da torre de hanoi de forma recursiva.
    Parametros: from, to, helper, numero de discos
    """
    if discos == 1:
        print('Move de {} para {}'.format(pino0, pino2))
    else:
        hanoi(pino0, pino1, pino2, discos - 1)
        hanoi(pino0, pino2, pino1, 1)
        hanoi(pino1, pino2, pino0, discos - 1)


if __name__ == '__main__':
    hanoi(0, 2, 1, 3)
