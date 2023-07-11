"""
Implementação do Gnome Sort ou Stupid Sort
"""


def gnomesort(lista):
    i = 0
    while i < len(lista):
        # caso a posição de i for 0 ou se o valor de i for maior ou igual
        # ao seu anterior, o gnomo apenas avançará uma casa
        if i == 0 or lista[i] >= lista[i - 1]:
            i += 1

        # caso o conteúdo da posição i seja menor ou igual a do seu anterior,
        # o gnomo trocará os valores de lugar e voltará uma posição
        # para validar a ordem
        else:
            lista[i], lista[i - 1] = lista[i - 1], lista[i]
            i -= 1

    return lista


def main():
    lista = [-1, 1, 0, -7, 7, -5, 5, 2, -2, 4, -4, 9, -9, -6, 6, -8, 8, -3, 3]
    # imprime a lista não ordenada
    print(f"Lista antes de ser ordenada: {lista}")
    lista = gnomesort(lista)
    # imprime a lista ordenada
    print(f"Lista após ordenação com Gnome Sort: {lista}")


if __name__ == "__main__":
    main()
