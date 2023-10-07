/* sequentialSearch.swift
Written by Roberto Martins on 07/10/2023
*/

func sequentialSearch(array: [Int], searchedElement: Int) -> Int {
    for index in 0..<array.count {
        if array[index] == searchedElement {
            return index
        }
    }
    return -1  // If element isn't found
}