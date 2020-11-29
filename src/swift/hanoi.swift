//
//  hanoi.swift
//  
//  Created by Matheus Torres on 13/11/20.
//

func hanoi(_ p1: Int, _ p2: Int, _ p3: Int, discos: Int) {
    if discos == 1 {
        print("Move de \(p1) para \(p2)")
    } else {
        hanoi(p1, p3, p2, discos: discos - 1)
        hanoi(p1, p2, p3, discos: 1)
        hanoi(p3, p2, p1, discos: discos - 1)
    }
}

hanoi(0, 2, 1, discos: 3)

