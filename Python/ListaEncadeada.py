# Lista Ligada:
#          _________    _________     _________     _________
# head --> | 2 | --|--> | 1 | --|-->  | 5 | --|-->  | 3 | --|--> None
#          ---------    ---------     ---------     ---------

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class MyList:
    def append(self, head, data):
        if head is None:
            head = Node(data)
        else:
            current = head
            while current.next:
                current = current.next
            current.next = Node(data)
        return head

    def display(self, head):
        current = head
        while current:
            print current.data, 
            current = current.next	

myList = MyList()
head = myList.append(None, 2)
myList.append(head, 1)
myList.append(head, 5)
myList.append(head, 3)
myList.display(head)