""" Implementacao do algoritmo de busca sentinela """


def busca_sentinela(list_to_search, value):
    """
    Implementacao de um algoritmo de busca sentinela.

    Argumentos:
    value: Any. Valor a ser buscado na lista
    list_to_search: list. lista na qual o valor sera buscado

    Retorna o indice do valor em "list_to_search" ou -1 caso nao exista nela.
    """
    list_to_search.append(value)
    list_index = 0
    while list_to_search[list_index] != value:
        list_index = list_index + 1
    list_to_search.pop()
    if list_index == len(list_to_search):
        return -1
    return list_index


if __name__ == "__main__":
    some_list = [1, 9, 2, 8, 7, 4, 5, 6, 4, 3, 10, 0]
    NUMBER_TO_FIND = 4
    NUMBER_INDEX = busca_sentinela(some_list, NUMBER_TO_FIND)
    print(some_list)
    if NUMBER_INDEX >= 0:
        print(
            "Found value {} at position {}.".format(
                NUMBER_TO_FIND, NUMBER_INDEX
            )
        )
    else:
        print("Could not find value {}.".format(NUMBER_TO_FIND))
