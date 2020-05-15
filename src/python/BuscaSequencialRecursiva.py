def busca_sequencial(valor, lista, tamanho):
    """Busca sequencial recursiva.
    
    Returns:
        Retorna o indice do valor na lista.
        Se nao encontrar retorna -1.
    """
    if tamanho == 0:
        return -1
    else:
        indice = busca_sequencial(valor, lista, tamanho-1)
        if indice < 0:
            if lista[tamanho-1] == valor:
                indice = tamanho-1
        return indice

if __name__ == '__main__':
    lista = [1, 9, 39, 4, 12, 38, 94, 37]
    for indice, valor in enumerate(lista):
    	print('Testando valor {} no indice {}'.format(valor, indice))
        assert busca_sequencial(valor, lista, len(lista)) == indice
