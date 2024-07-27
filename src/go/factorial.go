package main

import "fmt"

func Factorial(value int) int {
	if value == 1 {
		return 1
	}
	return value * Factorial(value-1)
}

func main() {
	fmt.Println("Factorial:", Factorial(6))
}
