"""
Arvore Binaria de Busca em Python
Kelvin Salton do Prado
2015
"""


class Arvore:
    def __init__(self, chave):
        self.chave = chave
        self.esquerda = None
        self.direita = None


# Metodos de Busca
def busca_recursiva(no, chave):
    if no is None:
        print(f"{chave} nao foi encontrado na arvore")
        return
    if no.chave == chave:
        print(f"{chave} foi encontrado na arvore")
        return no
    if chave > no.chave:
        busca_recursiva(no.direita, chave)
    else:
        busca_recursiva(no.esquerda, chave)


def busca_linear(no, chave):
    while no is not None:
        if no.chave == chave:
            return no
        elif chave > no.chave:
            no = no.direita
        else:
            no = no.esquerda
    return None


# Metodo de Insercao
def insere(no, chave):
    if no is None:
        no = Arvore(chave)
    else:
        if chave < no.chave:
            no.esquerda = insere(no.esquerda, chave)
        else:
            no.direita = insere(no.direita, chave)
    return no


# Metodos de Impressao
IMPRIME_ARVORE = ""


def pre_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    IMPRIME_ARVORE += str(no.chave) + ", "
    pre_ordem(no.esquerda)
    pre_ordem(no.direita)


def em_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    em_ordem(no.esquerda)
    IMPRIME_ARVORE += str(no.chave) + ", "
    em_ordem(no.direita)


def pos_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    pos_ordem(no.esquerda)
    pos_ordem(no.direita)
    IMPRIME_ARVORE += str(no.chave) + ", "


# Acha a Altura da Arvore
def maximo(a, b):
    if a > b:
        return a
    return b


def altura(no):
    if no is None:
        return 0
    return 1 + maximo(altura(no.esquerda), altura(no.direita))


# Metodos de Exclusao
def busca_no_pai(no, ch):
    no_pai = no
    while no is not None:
        if no.chave == ch:
            return no_pai
        no_pai = no
        if no.chave < ch:
            no = no.direita
        else:
            no = no.esquerda
    return no_pai


def maiorAesquerda(no):
    no = no.esquerda
    while no.direita is not None:
        no = no.direita
    return no


def exclui(no, ch):
    atual = busca_linear(no, ch)
    if atual is None:
        return False
    noPai = busca_no_pai(no, ch)
    if atual.esquerda is None or atual.direita is None:
        if atual.esquerda is None:
            substituto = atual.direita
        else:
            substituto = atual.esquerda
        if noPai is None:
            no = substituto
        elif ch > noPai.chave:
            noPai.direita = substituto
        else:
            noPai.esquerda = substituto
        # AQUI DA FREE(ATUAL)
    else:
        substituto = maiorAesquerda(atual)
        atual.chave = substituto.chave
        if substituto.esquerda is not None:
            atual.esquerda = substituto.esquerda
        else:
            atual.esquerda = None
        # FREE(substituto)
    return True


if __name__ == "__main__":
    arvore = Arvore(3)  # Cria arvore (raiz)
    # Insere varios valores na arvore
    arvore = insere(arvore, 2)
    arvore = insere(arvore, 1)
    arvore = insere(arvore, 4)
    arvore = insere(arvore, 6)
    arvore = insere(arvore, 8)
    arvore = insere(arvore, 5)
    arvore = insere(arvore, 7)
    arvore = insere(arvore, 0)

    busca_recursiva(arvore, 6)  # Busca que imprime na propria funcao

    if busca_linear(arvore, 6) is not None:  # Retorna o NO ou None se nao encontrou
        print("Valor encontrado")
    else:
        print("Valor nao encontrado")

    print(f"Altura: {altura(arvore)}")

    # Exclui varios valores
    exclui(arvore, 7)
    exclui(arvore, 5)
    exclui(arvore, 8)
    exclui(arvore, 3)

    # Chama os metodos de impressao
    IMPRIME = ""
    pre_ordem(arvore)
    print(f"PreOrdem: {IMPRIME}")
    IMPRIME = ""
    em_ordem(arvore)
    print(f"EmOrdem: {IMPRIME}")
    IMPRIME = ""
    pos_ordem(arvore)
    print(f"PosOrdem: {IMPRIME}")

    # Mostra a altura da arvore apos remover os itens
    print(f"Altura: {altura(arvore)}")










"""
Binary Search Tree in Python in English
Kelvin Salton do Prado
2015
"""

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Search Methods
def recursive_search(node, key):
    if node is None:
        print(f"{key} was not found in the tree")
        return
    if node.key == key:
        print(f"{key} was found in the tree")
        return node
    if key > node.key:
        recursive_search(node.right, key)
    else:
        recursive_search(node.left, key)

def linear_search(node, key):
    while node is not None:
        if node.key == key:
            return node
        elif key > node.key:
            node = node.right
        else:
            node = node.left
    return None

# Insertion Method
def insert(node, key):
    if node is None:
        node = TreeNode(key)
    else:
        if key < node.key:
            node.left = insert(node.left, key)
        else:
            node.right = insert(node.right, key)
    return node

# Printing Methods
PRINT_TREE = ""

def pre_order(node):
    global PRINT_TREE
    if node is None:
        return
    PRINT_TREE += str(node.key) + ", "
    pre_order(node.left)
    pre_order(node.right)

def in_order(node):
    global PRINT_TREE
    if node is None:
        return
    in_order(node.left)
    PRINT_TREE += str(node.key) + ", "
    in_order(node.right)

def post_order(node):
    global PRINT_TREE
    if node is None:
        return
    post_order(node.left)
    post_order(node.right)
    PRINT_TREE += str(node.key) + ", "

# Finding the Tree's Height
def maximum(a, b):
    if a > b:
        return a
    return b

def tree_height(node):
    if node is None:
        return 0
    return 1 + maximum(tree_height(node.left), tree_height(node.right))

# Deletion Methods
def find_parent(node, ch):
    parent_node = node
    while node is not None:
        if node.key == ch:
            return parent_node
        parent_node = node
        if node.key < ch:
            node = node.right
        else:
            node = node.left
    return parent_node

def largest_on_left(node):
    node = node.left
    while node.right is not None:
        node = node.right
    return node

def delete(node, ch):
    current = linear_search(node, ch)
    if current is None:
        return False
    parent = find_parent(node, ch)
    if current.left is None or current.right is None:
        if current.left is None:
            substitute = current.right
        else:
            substitute = current.left
        if parent is None:
            node = substitute
        elif ch > parent.key:
            parent.right = substitute
        else:
            parent.left = substitute
        # Free(current)
    else:
        substitute = largest_on_left(current)
        current.key = substitute.key
        if substitute.left is not None:
            current.left = substitute.left
        else:
            current.left = None
        # Free(substitute)
    return True

if __name__ == "__main__":
    tree = TreeNode(3)  # Create a tree (root)
    # Insert several values into the tree
    tree = insert(tree, 2)
    tree = insert(tree, 1)
    tree = insert(tree, 4)
    tree = insert(tree, 6)
    tree = insert(tree, 8)
    tree = insert(tree, 5)
    tree = insert(tree, 7)
    tree = insert(tree, 0)

    recursive_search(tree, 6)  # Search that prints within the function

    if linear_search(tree, 6) is not None:  # Returns the NODE or None if not found
        print("Value found")
    else:
        print("Value not found")

    print(f"Height: {tree_height(tree)}")

    # Delete various values
    delete(tree, 7)
    delete(tree, 5)
    delete(tree, 8)
    delete(tree, 3)

    # Call printing methods
    PRINT_TREE = ""
    pre_order(tree)
    print(f"PreOrder: {PRINT_TREE}")
    PRINT_TREE = ""
    in_order(tree)
    print(f"InOrder: {PRINT_TREE}")
    PRINT_TREE = ""
    post_order(tree)
    print(f"PostOrder: {PRINT_TREE}")

    # Display the height of the tree after removing items
    print(f"Height: {tree_height(tree)}")
