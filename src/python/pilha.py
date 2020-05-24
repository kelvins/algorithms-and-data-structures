""" Implementação da estrutura de dados 'Pilha' """

import random


class Stack:
    """
    Essa classe implementa a estrutura de dados chamada "pilha"
    """

    def __init__(self):
        self.__stack = []

    def push(self, value):
        """ Adiciona o valor (value) ao final da pilha """
        self.__stack.append(value)

    def pop(self):
        """ Remove o último valor da pilha """
        return self.__stack.pop()

    def show(self):
        """ Imprime a pilha no console """
        print(f'Stack: {self.__stack}')


def main():
    """
    Cria uma pilha e utiliza os métodos show, pop e push
    """
    stack = Stack()

    for _ in range(0, 10):
        stack.push(random.randint(10, 99))

    stack.show()

    stack.pop()
    stack.pop()

    stack.show()


if __name__ == '__main__':
    main()
