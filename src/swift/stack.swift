//
//  stack.swift
//
//
//  Created by Matheus Torres on 14/11/20.
//

class Stack {
    var stack: [Int] = []

    func push(_ value: Int) {
        stack.append(value)
    }

    func pop() {
        stack.removeLast()
    }

    func show() {
        print(stack)
    }

    func clean() {
        stack = []
    }
}

let stack = Stack()

stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)

stack.show()

stack.pop()
stack.pop()
stack.show()

