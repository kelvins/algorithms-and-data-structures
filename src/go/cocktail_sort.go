package main

import "fmt"

func CocktailSort(slice []int) {

	swapped := true
	begining := 0
	ending := len(slice) - 1

	for begining < ending && swapped {

		for index := begining; index < ending; index++ {
			if slice[index] > slice[index+1] {
				slice[index], slice[index+1] = slice[index+1], slice[index]
				swapped = true
			}
		}

		ending--

		if swapped {
			swapped = false
			for index := ending; index > begining; index-- {
				if slice[index] < slice[index-1] {
					slice[index], slice[index-1] = slice[index-1], slice[index]
					swapped = true
				}
			}
		}

		begining++
	}
}

func main() {
  slice := []int{1, 5, 8, 3, 7, 4, 9, 6, 2}
	fmt.Println("Slice:", slice)
	CocktailSort(slice)
	fmt.Println("CocktailSort:", slice)
}
