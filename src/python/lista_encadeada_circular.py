""" implementação de uma lista encadeada circular """

import unittest


class Node:
    def __init__(self, value):
        self.__value = value
        self.next = None

    def get_value(self):
        return self.__value


class CircularlyLinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def __len__(self):
        return self.__size

    def __iter__(self):
        node = self.__head
        while node:
            yield node
            if node == self.__tail:
                break
            node = node.next

    def __str__(self):
        items = ''
        for item in self.__iter__():
            items += str(item.get_value()) + ' '
        return items

    def __repr__(self):
        return self.__str__()

    def insert(self, value):
        new_node = Node(value)
        new_node.next = self.__head
        self.__head = new_node
        if self.__size == 0:
            self.__tail = new_node
        self.__tail.next = self.__head
        self.__size += 1

    def append(self, value):
        new_node = Node(value)
        if self.__size == 0:
            self.__head = new_node
        else:
            self.__tail.next = new_node
        self.__tail = new_node
        self.__tail.next = self.__head
        self.__size += 1

    def remove(self, value):
        prev_node = None
        found = False
        for curr_node in self.__iter__():
            if value == curr_node.get_value():
                found = True
                if prev_node:
                    prev_node.next = curr_node.next
                    if curr_node == self.__tail:
                        self.__tail = prev_node
                else:
                    if self.__size == 1:
                        self.__init__()
                        break
                    else:
                        self.__head = curr_node.next
                        self.__tail.next = self.__head
                        curr_node = None
                self.__size -= 1
            prev_node = curr_node
        if not found:
            raise ValueError(str(value) + ' not found in list')


class TestCircularlyLinkedList(unittest.TestCase):
    def setUp(self):
        self.list = CircularlyLinkedList()

    def test_insert(self):
        self.list.insert(1)
        self.list.insert(2)
        self.assertEqual('2 1 ', str(self.list))

    def test_append(self):
        self.list.append(1)
        self.list.append(2)
        self.assertEqual('1 2 ', str(self.list))

    def test_remove(self):
        self.list.insert(1)
        self.list.insert(2)
        self.list.append(3)
        self.list.append(4)
        self.list.remove(3)
        self.assertEqual('2 1 4 ', str(self.list))
        self.list.remove(2)
        self.assertEqual('1 4 ', str(self.list))
        self.list.remove(4)
        self.assertEqual('1 ', str(self.list))
        self.list.remove(1)
        self.assertEqual('', str(self.list))
        self.assertRaises(ValueError, self.list.remove, 9)

    def test_size(self):
        self.list.insert(1)
        self.list.append(2)
        self.list.insert(3)
        self.list.remove(2)
        self.assertEqual(2, len(self.list))


if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(
        TestCircularlyLinkedList
    )
    unittest.TextTestRunner(verbosity=2).run(suite)
