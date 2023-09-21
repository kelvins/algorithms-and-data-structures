//
//  hanoi.swift
//
//  Created by Matheus Torres on 13/11/20.
//

func hanoi(_ p1: Int, _ p2: Int, _ p3: Int, disks: Int) {
    if disks == 1 {
        print("Move de \(p1) para \(p2)")
    } else {
        hanoi(p1, p3, p2, disks: disks - 1)
        hanoi(p1, p2, p3, disks: 1)
        hanoi(p3, p2, p1, disks: disks - 1)
    }
}

hanoi(0, 2, 1, disks: 3)

