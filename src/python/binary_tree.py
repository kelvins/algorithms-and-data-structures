""" Implementação de uma árvore binária """


class Node:
    """
    Node class store the data and the pointers to the next nodes (left/right).
    """

    def __init__(self, data):
        self.right = self.left = None
        self.data = data


class BinaryTree:
    """
    Binary tree class provides some methods to insert, remove and print data.
    """

    def __init__(self):
        self.root = None

    def insert(self, data):
        new_node = Node(data)
        if self.root is None:
            self.root = new_node
        else:
            node = self.root
            while node is not None:
                if data <= node.data:
                    if node.left is None:
                        node.left = new_node
                        break
                    node = node.left
                else:
                    if node.right is None:
                        node.right = new_node
                        break
                    node = node.right

    def recursive_search(self, node, data):
        if node is None:
            return

        if node.data == data:
            return node

        if data > node.data:
            self.recursive_search(node.right, data)
        else:
            self.recursive_search(node.left, data)

    def linear_search(self, data):
        node = self.root
        while node is not None:
            if node.data == data:
                return node
            elif data > node.data:
                node = node.right
            else:
                node = node.left
        return None

    def __get_parent_node(self, data):
        node = self.root
        parent = self.root
        while node is not None:
            if node.data == data:
                return parent
            parent = node
            if node.data < data:
                node = node.right
            else:
                node = node.left
        return parent

    @staticmethod
    def __higher_left(node):
        node = node.left
        while node.right is not None:
            node = node.right
        return node

    def remove(self, data):
        node = self.linear_search(data)

        if node is None:
            return False

        parent = self.__get_parent_node(data)

        if node.left is None or node.right is None:
            if node.left is None:
                temp = node.right
            else:
                temp = node.left
            if parent is None:
                node = temp
            elif data > parent.data:
                parent.right = temp
            else:
                parent.left = temp
        else:
            temp = self.__higher_left(node)
            node.data = temp.data
            if temp.left is not None:
                node.left = temp.left
            else:
                node.left = None

        return True

    def get_height(self, root):
        if root is None:
            return -1

        height_left = self.get_height(root.left)
        height_right = self.get_height(root.right)

        if height_right > height_left:
            return height_right + 1
        return height_left + 1

    def level_order(self):
        height = self.get_height(self.root)
        for i in range(1, height + 2):
            self.__print_level(self.root, i)

    def __print_level(self, node, level):
        if node is None:
            return
        if level == 1:
            print("%d" % node.data, end=' ')
        elif level > 1:
            self.__print_level(node.left, level - 1)
            self.__print_level(node.right, level - 1)

    def in_order(self, node):
        if node is None:
            return
        self.in_order(node.left)
        print("%d" % node.data, end=' ')
        self.in_order(node.right)

    def pre_order(self, node):
        if node is None:
            return
        print("%d" % node.data, end=' ')
        self.pre_order(node.left)
        self.pre_order(node.right)

    def post_order(self, node):
        if node is None:
            return
        self.post_order(node.left)
        self.post_order(node.right)
        print("%d" % node.data, end=' ')


b_tree = BinaryTree()

tree_data = [3, 1, 2, 7, 8, 6, 5, 4, 9]

for curr_data in tree_data:
    b_tree.insert(curr_data)

b_tree.in_order(b_tree.root)
print('\n')
b_tree.pre_order(b_tree.root)
print('\n')
b_tree.post_order(b_tree.root)
print('\n')
b_tree.level_order()
print('\n')
print(b_tree.get_height(b_tree.root))
