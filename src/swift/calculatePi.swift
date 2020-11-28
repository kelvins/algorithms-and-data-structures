//
//  calculatePi.swift
//  
//
//  Created by Matheus Torres on 14/11/20.
//

func calculatePi(_ number: Int) -> Float {
    var denominator: Float = 1
    var operation: Float = 1
    var pi: Float = 0
    
    for _ in 0..<number {
        pi += operation * (4 / denominator)
        denominator += 2
        operation *= -1
    }
    
    return pi
}

print("PI 10: \(calculatePi(10))")
print("PI 1000: \(calculatePi(1000))")
print("PI 100000: \(calculatePi(100000))")
print("PI 10000000: \(calculatePi(10000000))")

