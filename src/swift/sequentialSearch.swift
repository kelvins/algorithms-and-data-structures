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

func main() {
    let numbers = [4, 7, 2, 9, 1, 5, 8]
    let elementToSearch = 5

    let result = sequentialSearch(array: numbers, searchedElement: elementToSearch)

    if result != -1 {
        print("Element \(elementToSearch) found at index \(result)")
    } else {
        print("Element \(elementToSearch) not found in the array.")
    }
}

main()
