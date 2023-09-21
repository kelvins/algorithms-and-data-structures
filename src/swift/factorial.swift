//
//  factorial.swift
//
//  Created by Matheus Torres on 13/11/20.
//

func factorial(_ number: Int) -> Int {
    var result: Int = 1
    for index in (1...number).reversed() {
        result = result * index
    }
    return result
}

print(factorial(5))

