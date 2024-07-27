package main

import "fmt"

// Iterative
func BubbleSortIterative(slice []int) {
	for index1 := len(slice) - 1; index1 > 0; index1-- {
		for index2 := 0; index2 < index1; index2++ {
			if slice[index2] > slice[index2+1] {
				slice[index2], slice[index2+1] = slice[index2+1], slice[index2]
			}
		}
	}
}

// Recursive
func BubbleSortRecursive(slice []int, size int) {
	swaps := 0
	for index := 0; index < size-1; index++ {
		if slice[index] > slice[index+1] {
			slice[index], slice[index+1] = slice[index+1], slice[index]
			swaps++
		}
	}
	if swaps != 0 {
		BubbleSortRecursive(slice, size-1)
	}
}

func main() {
	slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
	fmt.Println("Slice:", slice)
	BubbleSortIterative(slice)
	fmt.Println("BubbleSort:", slice)
}
