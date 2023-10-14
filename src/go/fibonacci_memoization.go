package main

import "fmt"

var memo = make(map[int]int)

func FibonacciMemoization(n int) int {
    if n <= 1 {
        return 1
    }

    // Check if the value is already memoized
    if val, ok := memo[n]; ok {
        return val
    }

    // Calculate Fibonacci recursively and store the result in memoization
    result := FibonacciMemoization(n-1) + FibonacciMemoization(n-2)
    memo[n] = result
    return result
}

func main() {
    n := 9
    fmt.Println("Fibonacci Memoization:", FibonacciMemoization(n))
}
