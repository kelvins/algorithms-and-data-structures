"""
!/usr/bin/env python
-*- coding: utf-8 -*-

Lista Ligada:
         _________    _________     _________     _________
head --> | 2 | --|--> | 1 | --|-->  | 5 | --|-->  | 3 | --|--> None
          ---------    ---------     ---------     ---------
"""


class Node:
    def __init__(self, value, next_node=None):
        self.__value = value
        self.next_node = next_node

    @property
    def value(self):
        return self.__value


class LinkedList:
    def __init__(self):
        self.__main_node = None

    def append(self, value):
        if self.__main_node is None:
            self.__main_node = Node(value)
            return

        curr_node = self.__main_node
        while curr_node.next_node is not None:
            curr_node = curr_node.next_node
        curr_node.next_node = Node(value)

    def remove(self, value):
        if self.__main_node is None:
            return

        left_node = None
        curr_node = self.__main_node

        if curr_node.value == value:
            self.__main_node = curr_node.next_node

        while True:
            left_node = curr_node
            curr_node = curr_node.next_node

            if curr_node is None:
                break

            if curr_node.value == value:
                left_node.next_node = curr_node.next_node

    def show(self):
        values = []
        curr_node = self.__main_node
        while curr_node is not None:
            values.append(curr_node.value)
            curr_node = curr_node.next_node
        print("LinkedList: {}".format(values))


def main():
    linked_list = LinkedList()

    linked_list.append(5)
    linked_list.append(9)
    linked_list.append(2)

    linked_list.show()

    linked_list.remove(9)

    linked_list.show()

    linked_list.remove(5)
    linked_list.remove(9)
    linked_list.remove(2)

    linked_list.show()

    linked_list.append(8)

    linked_list.show()


if __name__ == "__main__":
    main()
