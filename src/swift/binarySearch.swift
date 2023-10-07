//
//  binarySearch.swift
//  
//
//  Escrito por Roberto Martins no dia 07/10/2023
//  Baseado no código em C apresentado no verbete da Wikipedia sobre a busca binária

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
    return -1  // Se elemento não está na array
}
