package main

import "fmt"

func GnomeSort(slice []int) {
	pivot := 0
	size := len(slice)

	for pivot < size-1 {
		if slice[pivot] > slice[pivot+1] {
			slice[pivot], slice[pivot+1] = slice[pivot+1], slice[pivot]
			if pivot > 0 {
				pivot -= 2
			}
		}
		pivot++
	}
}

func main() {
  slice := []int{2, 5, 1, 7, 4, 9, 8, 6, 3}
	fmt.Println("Slice:", slice)
	GnomeSort(slice)
	fmt.Println("GnomeSort:", slice)
}
