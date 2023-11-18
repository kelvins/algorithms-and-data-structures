//
//  factorial.swift
//
//  Created by Matheus Torres on 13/11/20.
//

func factorial(_ number: Int) -> Int {
    if number <= 1 { return 1 }
    return number * factorial(number - 1)
}

print(factorial(7))
