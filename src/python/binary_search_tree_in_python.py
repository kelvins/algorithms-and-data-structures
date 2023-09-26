"""
Binary Search Tree in Python
Kelvin Salton do Prado
2015
"""

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Search Methods
def recursive_search(node, key):
    if node is None:
        print(f"{key} was not found in the tree")
        return
    if node.key == key:
        print(f"{key} was found in the tree")
        return node
    if key > node.key:
        recursive_search(node.right, key)
    else:
        recursive_search(node.left, key)

def linear_search(node, key):
    while node is not None:
        if node.key == key:
            return node
        elif key > node.key:
            node = node.right
        else:
            node = node.left
    return None

# Insertion Method
def insert(node, key):
    if node is None:
        node = TreeNode(key)
    else:
        if key < node.key:
            node.left = insert(node.left, key)
        else:
            node.right = insert(node.right, key)
    return node

# Printing Methods
PRINT_TREE = ""

def pre_order(node):
    global PRINT_TREE
    if node is None:
        return
    PRINT_TREE += str(node.key) + ", "
    pre_order(node.left)
    pre_order(node.right)

def in_order(node):
    global PRINT_TREE
    if node is None:
        return
    in_order(node.left)
    PRINT_TREE += str(node.key) + ", "
    in_order(node.right)

def post_order(node):
    global PRINT_TREE
    if node is None:
        return
    post_order(node.left)
    post_order(node.right)
    PRINT_TREE += str(node.key) + ", "

# Finding the Tree's Height
def maximum(a, b):
    if a > b:
        return a
    return b

def tree_height(node):
    if node is None:
        return 0
    return 1 + maximum(tree_height(node.left), tree_height(node.right))

# Deletion Methods
def find_parent(node, ch):
    parent_node = node
    while node is not None:
        if node.key == ch:
            return parent_node
        parent_node = node
        if node.key < ch:
            node = node.right
        else:
            node = node.left
    return parent_node

def largest_on_left(node):
    node = node.left
    while node.right is not None:
        node = node.right
    return node

def delete(node, ch):
    current = linear_search(node, ch)
    if current is None:
        return False
    parent = find_parent(node, ch)
    if current.left is None or current.right is None:
        if current.left is None:
            substitute = current.right
        else:
            substitute = current.left
        if parent is None:
            node = substitute
        elif ch > parent.key:
            parent.right = substitute
        else:
            parent.left = substitute
        # Free(current)
    else:
        substitute = largest_on_left(current)
        current.key = substitute.key
        if substitute.left is not None:
            current.left = substitute.left
        else:
            current.left = None
        # Free(substitute)
    return True

if __name__ == "__main__":
    tree = TreeNode(3)  # Create a tree (root)
    # Insert several values into the tree
    tree = insert(tree, 2)
    tree = insert(tree, 1)
    tree = insert(tree, 4)
    tree = insert(tree, 6)
    tree = insert(tree, 8)
    tree = insert(tree, 5)
    tree = insert(tree, 7)
    tree = insert(tree, 0)

    recursive_search(tree, 6)  # Search that prints within the function

    if linear_search(tree, 6) is not None:  # Returns the NODE or None if not found
        print("Value found")
    else:
        print("Value not found")

    print(f"Height: {tree_height(tree)}")

    # Delete various values
    delete(tree, 7)
    delete(tree, 5)
    delete(tree, 8)
    delete(tree, 3)

    # Call printing methods
    PRINT_TREE = ""
    pre_order(tree)
    print(f"PreOrder: {PRINT_TREE}")
    PRINT_TREE = ""
    in_order(tree)
    print(f"InOrder: {PRINT_TREE}")
    PRINT_TREE = ""
    post_order(tree)
    print(f"PostOrder: {PRINT_TREE}")

    # Display the height of the tree after removing items
    print(f"Height: {tree_height(tree)}")
