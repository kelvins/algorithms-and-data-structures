
#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random

class Stack:
    
    def __init__(self):
        self.__stack = []
        
    def push(self, value):
        self.__stack.append(value)
        
    def pop(self):
        return self.__stack.pop()
        
    def show(self):
        print("Stack: {}".format(self.__stack))


def main():
    stack = Stack()

    for _ in xrange(0, 10):
        stack.push(random.randint(10,99))

    stack.show()

    stack.pop()
    stack.pop()

    stack.show()


if __name__ == "__main__":
    main()
