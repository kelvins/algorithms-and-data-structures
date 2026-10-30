"""Implementação da estrutura de data 'Stack'"""

import random


class Stack:
    """
    Essa classe implementa a estrutura de data chamada "stack"
    """

    def __init__(self):
        self.__stack = []

    def push(self, value):
        """Adiciona o value (value) ao final da stack"""
        self.__stack.append(value)

    def pop(self):
        """Remove o last value da stack"""
        return self.__stack.pop()

    def show(self):
        """Imprime a stack no console"""
        print(f"Stack: {self.__stack}")


def main():
    """
    Cria uma stack e utiliza os métodos show, pop e push
    """
    stack = Stack()

    for _ in range(0, 10):
        stack.push(random.randint(10, 99))

    stack.show()

    stack.pop()
    stack.pop()

    stack.show()


if __name__ == "__main__":
    main()
