
package main

import (
    "fmt"
    "github.com/kelvins/golangalgorithms/fibonacci"
    "github.com/kelvins/golangalgorithms/exponenciacao"
    "github.com/kelvins/golangalgorithms/fatorial"
    "github.com/kelvins/golangalgorithms/hanoi"
)

func main() {
    fmt.Println( "Fibonacci : ", fibonacci.Fibonacci(9) )
    fmt.Println( "Exponenciacao : ", exponenciacao.Exponenciacao(5, 5) )
    fmt.Println( "Fatorial : ", fatorial.Fatorial(6) )
    fmt.Println( "Hanoi : " )
    hanoi.Hanoi(0, 2, 1, 3)
}
