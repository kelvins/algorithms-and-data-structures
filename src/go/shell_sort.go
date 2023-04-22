package main

import "fmt"

func ShellSort(slice []int) {
	size := len(slice)
	gap := 1
	var j int

	for gap < size {
		gap = 3*gap + 1
	}

	for gap > 1 {
		gap /= 3
		for index := gap; index < size; index++ {
			value := slice[index]
			j = index - gap

			for j >= 0 && value < slice[j] {
				slice[j+gap] = slice[j]
				j -= gap
			}
			slice[j+gap] = value
		}
	}
}

func main() {
  slice := []int{5, 1, 4, 2, 3, 6, 9, 7, 8}
	fmt.Println("Slice:", slice)
	ShellSort(slice)
	fmt.Println("ShellSort:", slice)
}
