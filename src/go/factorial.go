package main

import "fmt"

func Fatorial(value int) int {
	if value == 1 {
		return 1
	}
	return value * Fatorial(value-1)
}

func main() {
	fmt.Println("Fatorial:", Fatorial(6))
}
