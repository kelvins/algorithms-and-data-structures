# Lista Ligada:
#          _________    _________     _________     _________
# head --> | 2 | --|--> | 1 | --|-->  | 5 | --|-->  | 3 | --|--> None
#          ---------    ---------     ---------     ---------

class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class MyList:

    def __init__(self):
        self.head = None

    def append(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(data)

    def display(self):
        current = self.head
        while current:
            print current.data, 
            current = current.next	

myList = MyList()
myList.append(2)
myList.append(1)
myList.append(5)
myList.append(3)
myList.display()