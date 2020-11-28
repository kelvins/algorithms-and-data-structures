//
//  insertionSort.swift
//  
//
//  Created by Matheus Torres on 14/11/20.
//

func insertionSort(_ array: [Int]) -> [Int] {
    var newArray: [Int] = array
    for i in 1..<newArray.count {
        let key = newArray[i]
        var supp = i - 1
        while supp >= 0, newArray[supp] > key {
            newArray[supp + 1] = newArray[supp]
            supp -= 1
        }
        newArray[supp + 1] = key
    }
    return newArray
}

let arrayNaoOrdenado: [Int] = [92, 23, 42, 12, 54, 65, 1, 2, 8, 9, 31, 99]
print(insertionSort(arrayNaoOrdenado))

