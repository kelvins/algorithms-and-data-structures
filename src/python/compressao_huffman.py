# Huffman Tree
class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        # Symbol frequency
        self.freq = freq

        # Symbol (character)
        self.symbol = symbol

        # Left node of the current node
        self.left = left

        # Right node of the current node
        self.right = right

        # Tree direction (0/1)
        self.huff = ""


# Utility function to print
# Huffman codes for all symbols
# in the newly created Huffman tree
def print_nodes(node, val=""):
    # Huffman code for the current node
    new_val = val + str(node.huff)

    # If the node does not belong to the
    # leaf of the tree, then traverse inside
    # until reaching the leaf
    if node.left:
        print_nodes(node.left, new_val)
    if node.right:
        print_nodes(node.right, new_val)

    # If the node is at the leaf of the tree,
    # then display the Huffman code
    if not node.left and not node.right:
        print(f"{node.symbol} -> {new_val}")


# Characters for the Huffman tree
chars = ["a", "b", "c", "d", "e", "f"]

# Frequencies of the characters
freq = [5, 9, 12, 13, 16, 45]

# List containing the unused nodes
nodes = []

if __name__ == "__main__":
    # Converting characters and frequencies into
    # Huffman tree nodes
    for x in range(len(chars)):
        nodes.append(Node(freq[x], chars[x]))

    while len(nodes) > 1:
        # Sort all nodes in ascending order
        # based on their frequency
        nodes = sorted(nodes, key=lambda x: x.freq)

        # Select the two smallest nodes
        left = nodes[0]
        right = nodes[1]

        # Assign a directional value to these nodes
        # (left or right)
        left.huff = 0
        right.huff = 1

        # Combine the two smallest nodes into a new parent node
        # for them.
        new_node = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

        # Remove the two nodes and add the parent node
        # as a new node on top of the others
        nodes.remove(left)
        nodes.remove(right)
        nodes.append(new_node)

    # Huffman Tree ready!
    print_nodes(nodes[0])
