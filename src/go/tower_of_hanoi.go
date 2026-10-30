package main

import "fmt"

func Hanoi(peg0 int, peg2 int, peg1 int, number int) {
	if number == 1 {
		fmt.Println("Move from ", peg0, " to ", peg2)
	} else {
		Hanoi(peg0, peg1, peg2, number-1)
		Hanoi(peg0, peg2, peg1, 1)
		Hanoi(peg1, peg2, peg0, number-1)
	}
}

func main() {
	fmt.Println("Tower of Hanoi:")
	Hanoi(0, 2, 1, 3)
}
