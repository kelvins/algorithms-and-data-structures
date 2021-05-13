# Árvore Huffman
class node:
    def __init__(self, freq, symbol, left=None, right=None):
        # Frequência do Símbolo
        self.freq = freq

        # Símbolo (caracter)
        self.symbol = symbol

        # nó à esquerda do nó atual
        self.left = left

        # nó à direita do nó atual
        self.right = right

        # direção da árvore (0/1)
        self.huff = ''

# Função utilitária para imprimir
# códigos huffman para todos os símbolos
# na nova árvore huffman que sera criada


def printNodes(node, val=''):
    # código huffman para o nó atual
    newVal = val + str(node.huff)

    # se o nó não pertence á ponta da
    # árvore então caminha dentro do mesmo
    # até a ponta
    if(node.left):
        printNodes(node.left, newVal)
    if(node.right):
        printNodes(node.right, newVal)

    # Se o nó estiver na ponta da árore
    # então exibe o código huffman
    if(not node.left and not node.right):
        print(f"{node.symbol} -> {newVal}")


# caracteres para à árvore huffman
chars = ['a', 'b', 'c', 'd', 'e', 'f']

# frequência dos caracteres
freq = [5, 9, 12, 13, 16, 45]

# lista contendo os nós não utilizados
nodes = []

if __name__ == '__main__':
    # convertendo caracteres e frequência em
    # nós da árvore huffman
    for x in range(len(chars)):
        nodes.append(node(freq[x], chars[x]))

    while len(nodes) > 1:
        # Ordena todos os nós de forma ascendente
        # baseado em sua frequência
        nodes = sorted(nodes, key=lambda x: x.freq)

        # Seleciona os dois nós menores
        left = nodes[0]
        right = nodes[1]

        # Atribui um valor direcional à estes nós
        # (direita ou esquerda)
        left.huff = 0
        right.huff = 1

        # Combina os 2 nós menores para um novo nó pai
        # para eles.
        newNode = node(
            left.freq +
            right.freq,
            left.symbol +
            right.symbol,
            left,
            right)

        # remove os 2 nós e adiciona o nó pai
        # como um novo só sobre os outros
        nodes.remove(left)
        nodes.remove(right)
        nodes.append(newNode)

    # Árvore Huffman pronta!
    printNodes(nodes[0])
