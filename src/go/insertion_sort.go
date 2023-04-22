package main

import "fmt"

func InsertionSort(slice []int) {
	for index1 := 1; index1 < len(slice); index1++ {
		currentValue := slice[index1]
		index2 := index1 - 1

		for index2 >= 0 && currentValue < slice[index2] {
			slice[index2+1] = slice[index2]
			index2--
		}

		slice[index2+1] = currentValue
	}
}

func main() {
  slice := []int{9, 8, 7, 5, 1, 2, 4, 3, 6}
	fmt.Println("Slice:", slice)
	InsertionSort(slice)
	fmt.Println("InsertionSort:", slice)
}
