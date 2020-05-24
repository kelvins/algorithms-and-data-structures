""" Implementação de uma lista encadeada desordenada """


class Node:
    def __init__(self, value, next_node=None):
        self.__value = value
        self.next_node = next_node

    @property
    def value(self):
        return self.__value


class LinkedList:
    def __init__(self, *nodes):
        self.nodes = nodes

    def sorted(self):
        tmp_nodes = {node.next_node: node for node in self.nodes}
        sorted_nodes = list()
        current_node = None
        while current_node in tmp_nodes:
            current_node = tmp_nodes[current_node]
            sorted_nodes.insert(0, current_node)
        return sorted_nodes


if __name__ == '__main__':
    e = Node(5)
    d = Node(4, next_node=e)
    c = Node(3, next_node=d)
    b = Node(2, next_node=c)
    a = Node(1, next_node=b)

    linked_list = LinkedList(c, a, d, b, e)

    print('Unsorted linked list:')
    for node in linked_list.nodes:
        print(node.value)

    print('Sorted linked list:')
    for node in linked_list.sorted():
        print(node.value)
