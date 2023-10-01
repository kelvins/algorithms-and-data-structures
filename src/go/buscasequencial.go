package main

import "fmt"

func main() {
    myArray := []string{"c", "f", "g", "u"}
    fmt.Println("Element found: ", SearchPosition(myArray, "g"))
    fmt.Println("Element not found: ", SearchPosition(myArray, "i"))
}

// SearchPosition returns the position of the element in the array
func SearchPosition(myArray []string, element string) int {
    for i, v := range myArray {
        if v == element {
            return i
        }
    }
    return -1 // Return -1 if the element is not found in the array
}
