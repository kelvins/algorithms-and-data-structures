"""
Lista Duplamente Encadeada

A cabeca da lista sempre 'aponta' para o primeiro no
O rabo da lista sempre 'aponta' para o ultimo no

None <--- | 2 |  ---> None
None <--- | 2 | <---> | 5 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 | <---> | 20 | ---> None
"""

"""
Doubly Linked List

The head of the list always 'points' to the first node
The tail of the list always 'points' to the last node

None <--- | 2 |  ---> None
None <--- | 2 | <---> | 5 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 |  ---> None
None <--- | 2 | <---> | 5 | <---> | 12 | <---> | 20 | ---> None
"""

class Node:
    def __init__(self, data, previous, next):
        self.data = data
        self.previous = previous
        self.next = next

class DoublyLinkedList:
    head = None
    tail = None

    def append(self, data):
        """Append a new node to the list."""
        # Create a new node pointing to None (previous and next)
        new_node = Node(data, None, None)

        # If the head is None, the list is empty
        # Both the head and the tail receive the new node
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        # Otherwise, if there is already some value in the list
        else:
            # The previous 'points' to the tail (last added node)
            new_node.previous = self.tail
            # The next always points to None
            new_node.next = None
            # The next of the tail always points to the new node
            self.tail.next = new_node
            # The tail is now the new node
            self.tail = new_node

    def remove(self, data):
        """Remove a node from the list."""
        # The current node is the first node in the list
        current_node = self.head

        # Let's look for the data we want to remove
        # As long as the current node is valid
        while current_node is not None:
            # Check if it's the data we are looking for
            if current_node.data == data:
                # If the data we are looking for is in the first node
                # of the list, we have no previous
                if current_node.previous is None:
                    # The head 'points' to the next node in the list
                    self.head = current_node.next
                    # And the previous of the next node points to None
                    current_node.next.previous = None
                else:
                    # Example: Removing value 5
                    # ... <---> | 2 | <---> | 5 | <---> | 12 | <---> ...
                    #
                    # The next of value 2 now points to 12 and
                    # the previous of value 12 points to 2
                    #                     ---------------
                    # ... <---> | 2 | <---|--- | 5 | ---|---> | 12 | <---> ...
                    current_node.previous.next = current_node.next
                    current_node.next.previous = current_node.previous

            # If it's not the node we are looking for, move to the next one
            current_node = current_node.next

    def display(self):
        """Display all data in the list."""
        print("Doubly Linked List:")

        # The current node is the first node in the list
        current_node = self.head

        node = ""
        # For each valid node in the list
        while current_node is not None:
            if current_node.previous is None:
                node += "None "
            node += "<---> | " + str(current_node.data) + " | "
            if current_node.next is None:
                node += "<---> None"

            current_node = current_node.next
        print(node)
        print("=" * 80)


linked_list = DoublyLinkedList()

linked_list.append(2)
linked_list.display()
linked_list.append(5)
linked_list.display()
linked_list.append(12)
linked_list.display()
linked_list.append(20)
linked_list.display()

linked_list.remove(12)
linked_list.display()
linked_list.remove(5)
linked_list.display()
