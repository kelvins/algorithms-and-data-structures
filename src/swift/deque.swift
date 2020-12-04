//
//  deque.swift
//  
//
//  Created by Matheus Torres on 14/11/20.
//

class Deque {
    var deque: [Int] = []
    
    func addAtBeginning(_ value: Int) {
        deque.insert(value, at: 0)
    }
    
    func addAtEnd(_ value: Int) {
        deque.append(value)
    }
    
    func removeAtBeggining() {
        deque.removeFirst()
    }
    
    func removeAtEnd() {
        deque.removeLast()
    }
    
    func read() {
        print(deque)
    }
    
    func readReverse() {
        print(Array(deque.reversed()))
    }
}

let newDeque = Deque()

for n in 0...20 {
    newDeque.addAtEnd(n)
}

newDeque.addAtBeginning(666)
newDeque.addAtBeginning(1000)
newDeque.removeAtBeggining()
newDeque.addAtBeginning(616)

newDeque.removeAtEnd()

newDeque.read()
newDeque.readReverse()

