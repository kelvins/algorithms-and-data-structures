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
        print(f'{chave} nao foi encontrado na arvore')
        return
    if no.chave == chave:
        print(f'{chave} foi encontrado na arvore')
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
IMPRIME_ARVORE = ''


def pre_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    IMPRIME_ARVORE += str(no.chave) + ', '
    pre_ordem(no.esquerda)
    pre_ordem(no.direita)


def em_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    em_ordem(no.esquerda)
    IMPRIME_ARVORE += str(no.chave) + ', '
    em_ordem(no.direita)


def pos_ordem(no):
    global IMPRIME_ARVORE
    if no is None:
        return
    pos_ordem(no.esquerda)
    pos_ordem(no.direita)
    IMPRIME_ARVORE += str(no.chave) + ', '


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


if __name__ == '__main__':
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

    if (
        busca_linear(arvore, 6) is not None
    ):  # Retorna o NO ou None se nao encontrou
        print('Valor encontrado')
    else:
        print('Valor nao encontrado')

    print(f'Altura: {altura(arvore)}')

    # Exclui varios valores
    exclui(arvore, 7)
    exclui(arvore, 5)
    exclui(arvore, 8)
    exclui(arvore, 3)

    # Chama os metodos de impressao
    IMPRIME = ""
    pre_ordem(arvore)
    print(f'PreOrdem: {IMPRIME}')
    IMPRIME = ""
    em_ordem(arvore)
    print(f'EmOrdem: {IMPRIME}')
    IMPRIME = ""
    pos_ordem(arvore)
    print(f'PosOrdem: {IMPRIME}')

    # Mostra a altura da arvore apos remover os itens
    print(f'Altura: {altura(arvore)}')
