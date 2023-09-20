# Huffman Tree
class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        # Frequency of the symbol
        self.freq = freq

        # Symbol (character)
        self.symbol = symbol

        # Left node of the current node
        self.left = left

        # Right node of the current node
        self.right = right

        # Huffman code direction (0/1)
        self.huff = ""


# Utility function to print Huffman codes
# for all symbols in the newly created Huffman tree
def printNodes(node, val=""):
    # Huffman code for the current node
    new_val = val + str(node.huff)

    # If the node is not at the end of the tree,
    # then traverse inside it until the end
    if node.left:
        printNodes(node.left, new_val)
    if node.right:
        printNodes(node.right, new_val)

    # If the node is at the end of the tree,
    # then display the Huffman code
    if not node.left and not node.right:
        print(f"{node.symbol} -> {new_val}")


# Characters for the Huffman tree
chars = ["a", "b", "c", "d", "e", "f"]

# Frequencies of the characters
freq = [5, 9, 12, 13, 16, 45]

# List containing unused nodes
nodes = []

if __name__ == "__main__":
    # Convert characters and frequencies into
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
        newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

        # Remove the two nodes and add the parent node
        # as a new one above the others
        nodes.remove(left)
        nodes.remove(right)
        nodes.append(newNode)

    # Huffman Tree is ready!
    printNodes(nodes[0])
