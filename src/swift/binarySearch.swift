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

func main() {
    let sortedArray = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    let elementToSearch = 5

    let result = binarySearch(array: sortedArray, searchedElement: elementToSearch)

    if result != -1 {
        print("Element \(elementToSearch) found at index \(result)")
    } else {
        print("Element \(elementToSearch) not found in the array.")
    }
}

main()
