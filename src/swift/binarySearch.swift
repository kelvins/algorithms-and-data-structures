//
//  binarySearch.swift
//  
//
//  Written by Roberto Martins on 07/10/2023
//  Based on the C code presented in the Portuguese Wikipedia article for Binary Search

func binarySearch(array: [Int], searchedElement: Int) -> Int {
    var firstIndex: Int = 0
    var lastIndex: Int = array.count - 1
    var middleIndex: Int;
    while firstIndex <= lastIndex {
        middleIndex = (firstIndex + lastIndex) / 2
        if (searchedElement == array[middleIndex]) {
            return middleIndex
        }
        searchedElement < array[middleIndex] ? (lastIndex = middleIndex - 1) : (firstIndex = middleIndex + 1)
    }
    return -1  // If the searched element isn't in the array
}
