package main

import "fmt"

func FibonacciIterative(n int) int {
    if n <= 1 {
        return 1
    }

    a, b := 1, 1
    for i := 2; i <= n; i++ {
        a, b = b, a+b
    }
    return b
}

func main() {
    n := 9
    fmt.Println("Fibonacci Iterative:", FibonacciIterative(n))
}
