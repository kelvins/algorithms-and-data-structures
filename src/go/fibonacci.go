package main

import "fmt"

func Fibonacci(value int) int {
	if value <= 1 {
		return 1
	}
	return Fibonacci(value-1) + Fibonacci(value-2)
}

func main() {
	fmt.Println("Fibonacci:", Fibonacci(9))
}
