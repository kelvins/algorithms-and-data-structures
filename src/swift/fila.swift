//
//  fila.swift
//
//  Created by Matheus Torres on 14/11/20.
//

class Queue {
    var queue: [Int] = []
    
    func enqueue(_ value: Int) {
        self.queue.append(value)
    }
    
    func dequeue(at indexPath: Int) {
        self.queue.remove(at: indexPath)
    }
    
    func show() {
        print(self.queue)
    }
    
    func clear() {
        self.queue = []
    }
}

let queue = Queue()

for n in 0...10 { queue.enqueue(n) }
queue.show()
queue.dequeue(at: 2)
queue.dequeue(at: 6)
queue.show()





