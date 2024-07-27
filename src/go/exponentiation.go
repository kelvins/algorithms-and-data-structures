package main

import "fmt"

func Exponentiation(base int, exponent int) int {
	for index := 0; index < (exponent - 1); index++ {
		base *= exponent
	}
	return base
}

func main() {
	fmt.Println("Exponentiation:", Exponentiation(5, 5))
}
