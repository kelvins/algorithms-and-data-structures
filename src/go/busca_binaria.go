package main

import "fmt"

func BinarySearch(seq []int, element, start, end int) int {
	index := (start + end) / 2

	if index < len(seq) && seq[index] == element {
		return index
	}

	if start != end {
		if seq[index] < element {
			return BinarySearch(seq, element, index+1, end)
		}

		return BinarySearch(seq, element, start, index-1)
	}

	return -1
}

func main() {
  value := 7
	slice := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Println("Slice:", slice)
  index := BinarySearch(slice, value, 0, len(slice))
	fmt.Println("Value", value, "found in index:", index)
}
