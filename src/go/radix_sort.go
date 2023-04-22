package main

import "fmt"

func RadixSort(slice []int) {

	if len(slice) == 0 {
		return
	}

	length := len(slice)
	higher := slice[0]
	exp := 1
	var temp []int

	for index := 0; index < length; index++ {
		temp = append(temp, 0)
		if slice[index] > higher {
			higher = slice[index]
		}
	}

	for higher/exp > 0 {
		var bucket [10]int

		for index := 0; index < length; index++ {
      bucket[(slice[index]/exp)%10]++
		}

		for index := 1; index < 10; index++ {
      bucket[index] += bucket[index-1]
		}

		for index := length - 1; index >= 0; index-- {
      bucket[(slice[index]/exp)%10]--
			temp[bucket[(slice[index]/exp)%10]] = slice[index]
		}

		for index := 0; index < length; index++ {
			slice[index] = temp[index]
		}

    exp *= 10
	}
}

func main() {
	slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
	fmt.Println("Slice:", slice)
	RadixSort(slice)
	fmt.Println("RadixSort:", slice)
}
