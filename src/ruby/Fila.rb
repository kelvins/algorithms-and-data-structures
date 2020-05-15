
class Queue
    def initialize()
        @queue = []
    end
    
    def enqueue(value)
        @queue.push(value)
    end
    
    def dequeue()
        @queue.delete_at(0)
    end
    
    def display()
        print @queue.to_s + "\n"
    end
end

q = Queue.new()

q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.enqueue(4)
q.display()

q.dequeue()
q.dequeue()
q.display()