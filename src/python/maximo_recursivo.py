"""Exemplo de Máximo, utilizando recursão."""


def max_recursivo(vetor, maximo, indice):
    """Busca o valor máximo através usando recursão."""
    if vetor[indice] > maximo:
        maximo = vetor[indice]
    if indice < len(vetor) - 1:
        maximo = max_recursivo(vetor, maximo, indice+1)
    return maximo


if __name__ == '__main__':
    lista = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
    print(lista)
    print(f'Max: {max_recursivo(lista, lista[0], 0)}')
