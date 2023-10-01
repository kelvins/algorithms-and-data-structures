package main

import "fmt"

// Recursive Approach
func BinarySearch(seq []int, element, start, end int) int {
    index := (start + end) / 2 // Calculate the middle index

    // If the element is found
    if index < len(seq) && seq[index] == element {
        return index
    }

    // If the element is not found
    if start != end {
        // If the element is greater than the middle element
        if seq[index] < element {
            return BinarySearch(seq, element, index+1, end) // Search in the right side
        }

        // If the element is less than the middle element
        return BinarySearch(seq, element, start, index-1) // Search in the left side
    }

    return -1 // Element not found in the slice
}

func main() {
    value := 7
    slice := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
    fmt.Println("Slice:", slice)
    index := BinarySearch(slice, value, 0, len(slice))
    fmt.Println("Value", value, "found in index:", index)
}
