package main

import "fmt"

func MaxDivideAndConquer(array []int, start int, end int) int {
	if start == end {
		return array[start]
	}

	middle := (start + end) / 2
	aux1 := MaxDivideAndConquer(array, start, middle)
	aux2 := MaxDivideAndConquer(array, middle+1, end)

	if aux1 > aux2 {
		return aux1
	}

	return aux2
}

func RecursiveMinMax(array []int, min int, max int, index int) {
	if array[index] < min {
		min = array[index]
	}
	if array[index] > max {
		max = array[index]
	}
	if index < len(array)-1 {
		RecursiveMinMax(array, min, max, index+1)
	} else {
		fmt.Println("Minimum:", min)
		fmt.Println("Maximum:", max)
	}
}

func main() {
	slice := []int{2, 3, 9, 1, 6, 8, 5}
	RecursiveMinMax(slice, 999, 0, 0)
}
