class Deque:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def add_front(self, item):
        self.items.insert(0, item)

    def add_rear(self, item):
        self.items.append(item)

    def remove_front(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            raise IndexError("Deque is empty")

    def remove_rear(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("Deque is empty")

    def peek_front(self):
        if not self.is_empty():
            return self.items[0]
        else:
            raise IndexError("Deque is empty")

    def peek_rear(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            raise IndexError("Deque is empty")

    def __str__(self):
        return str(self.items)


if __name__ == "__main__":
    my_deque = Deque()

    my_deque.add_front(1)
    my_deque.add_rear(2)
    my_deque.add_front(3)

    print(my_deque)  # Output: [3, 1, 2]

    print(my_deque.remove_front())  # Output: 3
    print(my_deque.remove_rear())  # Output: 2

    print(my_deque.peek_front())  # Output: 1
    print(my_deque.peek_rear())  # Output: 1

    print(my_deque.size())  # Output: 1
