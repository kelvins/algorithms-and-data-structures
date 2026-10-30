"""Implement a stack data structure."""

import random


class Stack:
    """A stack data structure."""

    def __init__(self):
        self.__stack = []

    def push(self, value):
        """Print the stack."""
        self.__stack.append(value)

    def pop(self):
        """Remove and return the top value."""
        return self.__stack.pop()

    def show(self):
        """Print the stack."""
        print(f"Stack: {self.__stack}")


def main():
    """Create a stack and demonstrate its methods."""
    stack = Stack()

    for _ in range(0, 10):
        stack.push(random.randint(10, 99))

    stack.show()

    stack.pop()
    stack.pop()

    stack.show()


if __name__ == "__main__":
    main()
