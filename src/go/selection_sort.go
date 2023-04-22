package main

import "fmt"

func SelectionSort(slice []int) {
	for index1 := 0; index1 < len(slice)-1; index1++ {
		indexMin := index1

		for index2 := index1 + 1; index2 < len(slice); index2++ {
			if slice[index2] < slice[indexMin] {
				indexMin = index2
			}
		}

		if index1 != indexMin {
			slice[index1], slice[indexMin] = slice[indexMin], slice[index1]
		}
	}
}

func main() {
  slice := []int{1, 3, 2, 9, 7, 8, 5, 6, 4}
	fmt.Println("Slice:", slice)
	SelectionSort(slice)
	fmt.Println("SelectionSort:", slice)
}
