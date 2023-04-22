package main

import "fmt"

func CombSort(slice []int) {
	shrinkFactor := 1.247330950103979
	gap := len(slice)
	swapped := true
	i := 0

	for gap > 1 || swapped {
		if gap > 1 {
			gap = int(float64(gap) / shrinkFactor)
		}

		swapped = false
		i = 0

		for gap+i < len(slice) {
			if slice[i]-slice[i+gap] > 0 {
				slice[i], slice[i+gap] = slice[i+gap], slice[i]
				swapped = true
			}
			i++
		}
	}
}

func main() {
	slice := []int{6, 5, 8, 7, 3, 4, 2, 1, 9}
	fmt.Println("Slice:", slice)
	CombSort(slice)
	fmt.Println("CombSort:", slice)
}
