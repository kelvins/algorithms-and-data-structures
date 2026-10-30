package main

import "fmt"

func towerOfHanoi(sourcePeg int, targetPeg int, auxiliaryPeg int, diskCount int) {
	if diskCount == 1 {
		fmt.Println("Move from ", sourcePeg, " to ", targetPeg)
	} else {
		towerOfHanoi(sourcePeg, auxiliaryPeg, targetPeg, diskCount-1)
		towerOfHanoi(sourcePeg, targetPeg, auxiliaryPeg, 1)
		towerOfHanoi(auxiliaryPeg, targetPeg, sourcePeg, diskCount-1)
	}
}

func main() {
	fmt.Println("Tower of Hanoi:")
	towerOfHanoi(0, 2, 1, 3)
}
