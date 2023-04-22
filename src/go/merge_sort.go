package main

import "fmt"

func MergeSort(slice []int) {
	if len(slice) > 1 {
		half := len(slice) / 2

		var sliceLeftSide []int
		var sliceRightSide []int

		for index := 0; index < half; index++ {
			sliceLeftSide = append(sliceLeftSide, slice[index])
		}

		for index := half; index < len(slice); index++ {
			sliceRightSide = append(sliceRightSide, slice[index])
		}

		MergeSort(sliceLeftSide)
		MergeSort(sliceRightSide)

		i := 0
		j := 0
		k := 0

		for i < len(sliceLeftSide) && j < len(sliceRightSide) {
			if sliceLeftSide[i] < sliceRightSide[j] {
				slice[k] = sliceLeftSide[i]
				i++
			} else {
				slice[k] = sliceRightSide[j]
				j++
			}
			k++
		}

		for i < len(sliceLeftSide) {
			slice[k] = sliceLeftSide[i]
			i++
			k++
		}

		for j < len(sliceRightSide) {
			slice[k] = sliceRightSide[j]
			j++
			k++
		}
	}
}

func main() {
  slice := []int{4, 6, 7, 1, 2, 3, 5, 9, 8}
	fmt.Println("Slice:", slice)
	MergeSort(slice)
	fmt.Println("MergeSort:", slice)
}
