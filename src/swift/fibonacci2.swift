//
//  fibonacci2.swift
//
//  Created by Andre Schlaepfer on 30/08/21.
//
// funcao fibonacci sem loops explicitos
// A complexidade desse algoritmo é dada pela complexidade
// de pow(base, expoente)

import Foundation

func fibonacci(_ number: Int) -> Int
{
    let a = (1+sqrt(5))/2
    let b = (1-sqrt(5))/2
    let n = Double(number) // pow(x,y) só recebe Double
    let fib = (pow(a, n) - pow(b, n))/sqrt(5)
    let result = floor(fib)
    return Int(result)
    
}

for i in 0...15{
    print(fibonacci(i))
}


