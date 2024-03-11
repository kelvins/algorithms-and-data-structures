"""
Doubly Linked List

The 'head' of the list always points to the first node
The 'tail' of the list always points to the final node

None <--- | 2 |  ---> None
None <--- | 2 | <---> | 5 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 | <---> | 20 | ---> None
"""


class Node:
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next


class DoublyLinkedList:
    head = None
    tail = None

    def append(self, data):
        # Creates a new node pointing to None (prev and next)
        new_node = Node(data, None, None)

        # If the list is empty, both head and tail point to the new node
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            # For a non-empty list, adjust pointers to add the new node at the end
            new_node.prev = self.tail  # New node's prev points to the current tail
            self.tail.next = new_node  # Current tail's next points to the new node
            self.tail = new_node  # Update tail to be the new node

        # No additional 'new_node.next = None' is needed as it's already None by default

    def delete(self, data):
        """Deletes a node from the list"""
        """ Current node is first node in the list"""
        curr_node = self.head

        # We search for the data we want to delete
        # While current node is not invalid
        while curr_node is not None:
            # Verifica se eh o dado que estamos buscando
            if curr_node.data == data:
                # If data we are looking for is in first node
                # If we do not have a previous node in the list
                if curr_node.prev is None:
                    # Head points to next node in the list
                    self.head = curr_node.next
                    # And the previous of the next node does not point to None
                    curr_node.next.prev = None
                else:
                    # Example: Deleting the value 5
                    # ... <---> | 2 | <---> | 5 | <---> | 12 | <---> ...
                    #
                    # Next node of 2 will now point to 12 instead of 5
                    # Previous node of 12 will not point to 2 instead of 5
                    #                     ---------------
                    # ... <---> | 2 | <---|--- | 5 | ---|---> | 12 | <---> ...
                    curr_node.prev.next = curr_node.next
                    curr_node.next.prev = curr_node.prev

            # If current node does not hold desired data, move to next node
            curr_node = curr_node.next

    def display(self):
        """Displays all data in the list"""
        print("Doubly Linked List: ")

        # Current node is head of the list
        curr_node = self.head

        node = ""
        # For each valid node in the list
        while curr_node is not None:
            if curr_node.prev is None:
                node += "None "
            node += "<---> | " + str(curr_node.data) + " | "
            if curr_node.next is None:
                node += "<---> None"

            curr_node = curr_node.next
        print(node)
        print("=" * 80)


list = DoublyLinkedList()

list.append(2)
list.display()
list.append(5)
list.display()
list.append(12)
list.display()
list.append(20)
list.display()

list.delete(12)
list.display()
list.delete(5)
list.display()
