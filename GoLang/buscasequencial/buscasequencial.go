package main

import "fmt"

func main() {
	myArray := []string{"c", "f", "g", "u"}
	fmt.Println("Element found: ", SearchPosition(myArray, "g"))
	fmt.Println("Element found: ", SearchPosition(myArray, "i"))
}

func SearchPosition(myArray []string, element string) int {
	for i, v := range myArray {
		if v == element {
			return i
		}
	}
	return -1
}
