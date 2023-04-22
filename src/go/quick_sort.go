package main

import "fmt"

func QuickSort(slice []int) {
	quick(slice, 0, len(slice)-1)
}

func quick(slice []int, start int, end int) {
	if start < end {
		pivotIndex := split(slice, start, end)
		quick(slice, start, pivotIndex-1)
		quick(slice, pivotIndex+1, end)
	}
}

func split(slice []int, start int, end int) int {
	pivot := slice[end]
	j := start

	for index := start; index < end; index++ {
		if slice[index] < pivot {
			slice[index], slice[j] = slice[j], slice[index]
			j++
		}
	}

	if pivot <= slice[j] {
		slice[end] = slice[j]
		slice[j] = pivot
	}

	return j
}

func main() {
	slice := []int{2, 1, 8, 4, 3, 7, 6, 5, 9}
	fmt.Println("Slice:", slice)
	QuickSort(slice)
	fmt.Println("QuickSort:", slice)
}
