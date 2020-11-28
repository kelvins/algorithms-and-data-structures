//
//  fatorial.swift
//  
//  Created by Matheus Torres on 13/11/20.
//

func fatorial(_ number: Int) -> Int {
    var result: Int = 1
    for index in (1...number).reversed() {
        result = result * index
    }
    return result
}

print(fatorial(5))

