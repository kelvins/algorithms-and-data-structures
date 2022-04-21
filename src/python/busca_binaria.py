""" Implementação do algoritmo de busca binária com recursão """


def busca_binaria(valor, vetor, esquerda, direita):
    """
    Implementação de um algoritmo de busca binária com recursão.

    Argumentos:
    valor: Any. Valor a ser buscado na lista
    vetor: list. lista ordenada na qual o valor será buscado
    esquerda: Any. Valor inicial da metade buscada
    direita: Any. Valor final da metade buscada

    Retorna o índice do valor em "vetor" ou -1 caso não exista nela.
    """
    meio = int((esquerda + direita) / 2)

    if esquerda <= direita:
        if valor > vetor[meio]:
            esquerda = meio + 1
            return busca_binaria(valor, vetor, esquerda, direita)
        elif valor < vetor[meio]:
            direita = meio - 1
            return busca_binaria(valor, vetor, esquerda, direita)
        return meio
    return -1


lista = [0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12]
print(busca_binaria(12, lista, 0, len(lista) - 1))
