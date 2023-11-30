
class Node:

    def __init__(self,value,rptr=None) -> None:
        self.value = value
        self.rptr = rptr

    @property
    def get_value(self):
        return self.value
    
    @property
    def next(self):
        return self.rptr
    
    @next.setter
    def next(self,ptr):
        self.rptr = ptr
    

class Unordered_Linked_List:
    def __init__(self) -> None:
        self.first_node = None
    
    def insert(self,value): # inserts a new node with the given value
        if self.first_node is None:
            self.first_node = Node(value)
        else:
            tmp = Node(value)
            tmp.next = self.first_node
            self.first_node = tmp
    
    def find(self,value): # returns true if the specified value is in your list
        ptr = self.first_node
        while ptr is not None:
            if ptr.value == value:
                print(f'{value} is in your list')
                return True
            else:
                ptr = ptr.next
        
        print(f'{value} is not in your list')
        return False
    
    def size(self): # returns size of the list
        ptr = self.first_node
        i = 0
        while ptr is not None:
            ptr = ptr.next
            i+=1
        print(f'Your list is of size {i}')
        return i
    
    def remove(self,value): # removes all instances of a given value
        ptr = self.first_node
        prev = None
        while ptr is not None:
            if ptr.value == value:
                if ptr == self.first_node:
                    tmp = ptr.next
                    self.first_node = tmp
                else:
                    prev.next = ptr.next
            
            prev = ptr
            ptr = ptr.next
    
    def show(self):
        ptr = self.first_node
        val = []
        while ptr is not None:
            val.append(ptr.get_value)
            ptr = ptr.next
        
        print(val)

def main():
    list = Unordered_Linked_List()

    list.insert(1)
    list.insert(3)
    list.insert(5)
    list.insert(2)

    list.size()
    list.show()

    list.find(3)
    list.find(9)

    list.remove(1)
    list.remove(3)
    list.remove(5)
    list.remove(2)

    list.show()

    list.insert(1)
    list.insert(3)
    list.insert(5)
    list.insert(3)
    
    list.show()

    list.remove(3)

    list.show()



                
if __name__ == "__main__":
    main()


