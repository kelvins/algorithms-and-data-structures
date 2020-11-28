//
//  fatorial.swift
//
//  Created by Matheus Torres on 13/11/20.
//

func fatorial(_ number: Int) -> Int {
    if number <= 1 { return 1 }
    return number * fatorial(number - 1)
}

print(fatorial(7))
