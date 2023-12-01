class Node:
    def __init__(self, value):
        self.value = value
        self.left_ptr = None

    @property
    def prev(self):
        return self.left_ptr

    @prev.setter
    def prev(self, ptr):
        self.left_ptr = ptr

    @property
    def get_value(self):
        return self.value


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def enqueue(self, value):
        new = Node(value)
        self.length += 1
        # if empty make new node both head and tail of queue
        if self.head is None:
            self.head = new
            self.tail = new
        # otherwise add new node to end of queue and update tail
        else:
            self.tail.prev = new
            self.tail = new

    def dequeue(self):
        if self.length == 0:
            print("Queue is empty, cannot dequeue")
            return
        else:
            tmp = self.head
            self.head = self.head.prev
            self.length -= 1
            return tmp.get_value

    def show(self):
        # first element is the head of the queue
        ptr = self.head
        val = []
        while ptr is not None:
            val.append(ptr.get_value)
            ptr = ptr.prev

        print(val)

    def length(self):
        return self.length


def main():
    queue = Queue()

    print("Queuing 1 and 7")
    queue.enqueue(1)
    queue.show()
    print(f"Queue is length {queue.length}")
    queue.enqueue(7)
    queue.show()
    print(f"Queue is length {queue.length}")

    print(f"Dequeuing {queue.dequeue()}")
    queue.show()
    print(f"Queue is length {queue.length}")
    print(f"Dequeuing {queue.dequeue()}")
    queue.show()
    print(f"Queue is length {queue.length}")

    
    print(f"Dequeuing {queue.dequeue()}")
    print(f"Queue is length {queue.length}")

    print("Queueing 12")
    queue.enqueue(12)
    queue.show()
    print(f"Queue is length {queue.length}")


if __name__ == "__main__":
    main()
