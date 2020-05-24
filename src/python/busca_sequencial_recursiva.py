""" Implementaçao do algoritmo de busca sequencial com recursão """


def busca_sequencial(valor, lista, index):
    """Busca sequencial recursiva.

    Returns:
    Retorna o indice do valor na lista.
    Se nao encontrar retorna -1.
    """
    if len(lista) == 0 or index == len(lista):
        return -1
    if lista[index] == valor:
        return index
    return busca_sequencial(valor, lista, index + 1)


if __name__ == '__main__':
    uma_lista = [1, 9, 39, 4, 12, 38, 94, 37]
    for indice, valor_na_lista in enumerate(uma_lista):
        print('Testando valor {} no indice {}'.format(valor_na_lista, indice))
        assert busca_sequencial(valor_na_lista, uma_lista, 0) == indice
