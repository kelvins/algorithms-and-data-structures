class Node:
    def __init__(self, key: int) -> None:
        self.key = key
        self.next = None


class DynamicQueue:
    def __init__(self) -> None:
        self.__begin = None
        self.__end = None

    def is_empty(self) -> bool:
        return self.__begin is None

    def enqueue(self, val: int) -> None:
        node = Node(val)
        if self.is_empty():
            self.__begin = node
        else:
            self.__end.next = node
        self.__end = node

    def dequeue(self) -> Node | None:
        if self.is_empty():
            return None
        node = self.__begin
        self.__begin = self.__begin.next
        if self.is_empty():
            self.__end = None
        return node

    def show(self) -> None:
        curr = self.__begin
        while curr:
            print(f"[{curr.key}]->", end="")
            curr = curr.next
        print()

    def size(self) -> int:
        size, curr = 0, self.__begin
        while curr:
            size += 1
            curr = curr.next
        return size


def main():
    queue = DynamicQueue()
    queue.enqueue(10)
    queue.enqueue(15)
    queue.enqueue(42)
    queue.enqueue(70)
    queue.show()
    print("size: ", queue.size())
    print()
    queue.dequeue()
    queue.show()
    print("size: ", queue.size())
    print()
    queue.dequeue()
    queue.show()
    print("size: ", queue.size())


if __name__ == "__main__":
    main()
