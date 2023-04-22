package main

import "fmt"

func Exponenciacao(base int, expoente int) int {
	for index := 0; index < (expoente - 1); index++ {
		base *= expoente
	}
	return base
}

func main() {
	fmt.Println("Exponenciacao:", Exponenciacao(5, 5))
}
