# Algoritmo Deque em Ruby
# Carlos Alves
# https://github.com/EuCarlos

class Deque
    attr_accessor :deque

    def initialize(deque = [])
        self.deque = deque
    end

    # adds an item in front of the deque:
    def insert_front(value)
        self.deque.unshift(value)
    end

    # adds an item in back of the deque:
    def insert_last(value)
        self.deque.push(value)
    end

    # adds an item in front of the deque:
    def delete_front()
        self.deque.shift() if self.deque.length != 0
    end

    # adds an item in back of the deque:
    def delete_last()
        self.deque.pop() if self.deque.length != 0
    end

    # gets the item at the front of the queue:
    def read_front()
        return self.deque.length >= 1 ? self.deque[0] : 'Lista está vazia'
    end

    # gets the item at the last of the queue:
    def read_rear()
        return self.deque.length >= 1 ? self.deque[-1] : 'Lista está vazia'
    end

    # checks whether deque is full or not
    def is_full()
        result = self.deque.length >= 1 ? 'está' : 'não esta'
        return "Lista #{result} cheia!"
    end

    # checks whether deque is empty or not
    def is_empty()
        result = self.deque.length == 0 ? 'está' : 'não esta'
        return "Lista #{result} vazia"
    end
end

def main
    # test with full list
    deque = Deque.new([86, 16, 10, 39])

    deque.insert_front(54)
    deque.insert_last(91)

    deque.delete_front
    deque.delete_last

    puts deque.read_front
    puts deque.read_rear

    puts deque.is_full
    puts deque.is_empty

    # test with empty list
    deque_empty = Deque.new
    puts deque_empty.is_full
    puts deque_empty.is_empty
end

main()