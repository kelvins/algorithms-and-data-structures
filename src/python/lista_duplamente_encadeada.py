"""
Lista Duplamente Encadeada

A cabeca da lista sempre 'aponta' para o primeiro no
O rabo da lista sempre 'aponta' para o ultimo no

None <--- | 2 |  ---> None
None <--- | 2 | <---> | 5 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 | <---> | 20 | ---> None
"""


class No:
    def __init__(self, dado, anterior, proximo):
        self.dado = dado
        self.anterior = anterior
        self.proximo = proximo


class ListaDuplamenteEncadeada:

    cabeca = None
    rabo = None

    def acrescentar(self, dado):
        """ Acrescenta um novo no a lista. """
        # Cria um novo no apontando para None (anterior e proximo)
        novo_no = No(dado, None, None)

        # Se a cabeca eh None a lista esta vazia
        # Tanto a cabeca quanto o rabo recebem o novo no
        if self.cabeca is None:
            self.cabeca = novo_no
            self.rabo = novo_no
        # Caso contrario, se ja existir algum valor na lista
        else:
            # O anterior 'aponta' para o rabo (ultimo no adicionado)
            novo_no.anterior = self.rabo
            # O proximo sempre aponta para None
            novo_no.proximo = None
            # O proximo do rabo sempre aponta para o novo no
            self.rabo.proximo = novo_no
            # O rabo agora eh o novo no
            self.rabo = novo_no

    def remover(self, dado):
        """ Remove um no da lista. """
        # O no atual eh o primeiro no da lista
        no_atual = self.cabeca

        # Vamos procurar pelo dado que queremos remover
        # Equanto o no atual for valido
        while no_atual is not None:
            # Verifica se eh o dado que estamos buscando
            if no_atual.dado == dado:
                # Se o dado que estamos buscando esta no primeiro no
                # da lista, nao temos anterior
                if no_atual.anterior is None:
                    # A cabeca 'aponta' para o proximo no da lista
                    self.cabeca = no_atual.proximo
                    # E o anterior do proximo no aponta para None
                    no_atual.proximo.anterior = None
                else:
                    # Exemplo: Removendo o valor 5
                    # ... <---> | 2 | <---> | 5 | <---> | 12 | <---> ...
                    #
                    # O proximo do valor 2 passa a apontar para o 12 e
                    # o anterior do valor 12 passa a apontar para o 2
                    #                     ---------------
                    # ... <---> | 2 | <---|--- | 5 | ---|---> | 12 | <---> ...
                    no_atual.anterior.proximo = no_atual.proximo
                    no_atual.proximo.anterior = no_atual.anterior

            # Se nao eh o no que estamos buscando va para o proximo
            no_atual = no_atual.proximo

    def mostrar(self):
        """ Mostra todos os dados da lista. """
        print("Lista Duplamente Encadeada:")

        # O no atual eh o primeiro no da lista
        no_atual = self.cabeca

        no = ""
        # Para cada no valido da lista
        while no_atual is not None:
            if no_atual.anterior is None:
                no += "None "
            no += "<---> | " + str(no_atual.dado) + " | "
            if no_atual.proximo is None:
                no += "<---> None"

            no_atual = no_atual.proximo
        print(no)
        print("=" * 80)


lista = ListaDuplamenteEncadeada()

lista.acrescentar(2)
lista.mostrar()
lista.acrescentar(5)
lista.mostrar()
lista.acrescentar(12)
lista.mostrar()
lista.acrescentar(20)
lista.mostrar()

lista.remover(12)
lista.mostrar()
lista.remover(5)
lista.mostrar()
