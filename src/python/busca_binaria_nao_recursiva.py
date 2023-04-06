"""
Busca binária (não recursiva)

Objetivo: Implementar o algoritmo de busca binária de forma não recursiva
          (evitando da propria função ter de ser chamar diversas vezes)
          com o intuito de ser mais simples de ser explicado ao ir cortando o array

Por: Samuel Sampaio @samukasmk [20230306]
"""


def busca_binaria_nao_recursiva(array_de_elementos, elemento_para_buscar):
    # repete esse laço condicional enquanto ainda existirem elementos no array
    while len(array_de_elementos) > 0:
        # obtem o elemento do meio do array
        indice_do_meio = len(array_de_elementos) // 2
        elemento_do_meio = array_de_elementos[indice_do_meio]

        if elemento_para_buscar == elemento_do_meio:
            # elemento localizado retornando verdadeiro
            return True

        elif elemento_para_buscar > elemento_do_meio:
            # corta o array atual apenas obtendo os elementos da direita
            array_de_elementos = array_de_elementos[indice_do_meio + 1:]

        elif elemento_para_buscar < elemento_do_meio:
            # corta o array atual apenas obtendo os elementos da esquerda
            array_de_elementos = array_de_elementos[:indice_do_meio]

    # se chegar ao fim do arrays cortados e o elemento não for encontrado retorna falso
    return False


if __name__ == '__main__':
    from datetime import datetime
    from random import randint

    print('Criando um array gigante, com 10 bilhões de números aleatórios, aguarde...')

    # cria um array com 10 bilhões de elementos
    array_com_10_bilhoes_de_elementos = [randint(1, 10000000) for i in range(10000000)]
    array_com_10_bilhoes_de_elementos.sort()

    # obtem o ultimo item valido do array no [pior caso] de O(log n)
    ultimo_elemento = array_com_10_bilhoes_de_elementos[-1]

    # obtem a hora inicial
    hora_inicio = datetime.now()

    # testa a busca binária de forma não recursiva
    resultado = busca_binaria_nao_recursiva(array_com_10_bilhoes_de_elementos, ultimo_elemento)

    # obtem a hora final
    hora_fim = datetime.now()

    if resultado is True:
        print(f'Elemento ({ultimo_elemento}) localizado em: ({hora_fim - hora_inicio})')
    else:
        print(f'ERRO! último elemento obtido do array gerado não foi localizado! em: ({hora_fim - hora_inicio})')

"""
python ./busca_binaria_nao_recursiva
Criando um array gigante, com 10 bilhões de números aleatórios, aguarde...
Elemento (9999999) localizado em: (0:00:00.307458)
"""
