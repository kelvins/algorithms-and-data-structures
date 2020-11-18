//
//  fatorial.swift
//
//  Created by Matheus Torres on 13/11/20.
//

func fibonacci(_ number: Int) -> Int {
    if number <= 1 {
        return number
    } else {
        var currentNumber: Int = 1
        var nextNumber: Int = 0
        
        for _ in 0...number {
            let tempNumber = nextNumber
            nextNumber = nextNumber + currentNumber
            currentNumber = tempNumber
        }
        
        return currentNumber
    }
}

func fibonacciRecursiva(_ number: Int) -> Int {
    if number < 2 {
        return number
    } else {
        return (fibonacciRecursiva(number - 1) + fibonacciRecursiva(number - 2))
    }
}

let index: Int = 15

print(fibonacci(index))
print(fibonacciRecursiva(index))
