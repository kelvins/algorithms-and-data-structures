""" Exemplo de Maximo, utilizando recursao e divisao e conquista """

def max_dc(vetor, inicio, fim):
    """
    Busca o valor máximo através da divisão e conquista.
    Usa os valores início e fim para a recursão
    """
    if inicio == fim:
        return vetor[inicio]
    meio = int((inicio+fim)/2)
    aux1 = max_dc(vetor, inicio, meio)
    aux2 = max_dc(vetor, meio+1, fim)
    if aux1 > aux2:
        return aux1
    return aux2

uma_lista = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
print(uma_lista)
print('\nMax:' + str(max_dc(uma_lista, 0, len(uma_lista)-1)))
