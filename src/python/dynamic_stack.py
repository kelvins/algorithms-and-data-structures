# Stack: Last In - First Out (LIFO)

# Define node format: value and a pointier to next
class Node:
    def __init__(self, value: int) -> None:
        self.value = value
        self.next = None


class DynamicStack:
    def __init__(self) -> None:
        self.__first = None
    
    def isEmpty(self) -> bool:
        if not self.__first:
            return True
        return False
    
    def push(self,value: int):
        node = Node(value)
        node.next = self.__first
        self.__first = node

    def pop(self) -> int:
        if self.isEmpty():
            raise Exception('Stack is empty!')
        removedElement = self.__first.value
        self.__first = self.__first.next
        return removedElement
        

    def show(self) -> None:
        node = self.__first
        print('[', end=' ')
        while(node):
            print(node.value, end=' ')
            node = node.next
        print(']')

def main() -> None:
    dynamic_stack = DynamicStack()

    print(f'Push(1,2,4):')
    dynamic_stack.push(1)
    dynamic_stack.push(2)
    dynamic_stack.push(4)
    
    dynamic_stack.show()

    print(f'Remove last: {dynamic_stack.pop()}')
    print(f'Remove last: {dynamic_stack.pop()}')
    print(f'Remove last: {dynamic_stack.pop()}')
    print('Empty stack!')
    dynamic_stack.show()

if __name__ == "__main__":
    main()