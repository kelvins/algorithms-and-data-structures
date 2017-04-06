
package main

import (
    "fmt"
    "../GoLang/fibonacci"
    "../GoLang/exponenciacao"
    "../GoLang/fatorial"
    "../GoLang/hanoi"
    "../GoLang/bubblesort"
    "../GoLang/selectionsort"
    "../GoLang/insertionsort"
    "../GoLang/mergesort"
)

func main() {
    fmt.Println("Fibonacci : ", fibonacci.Fibonacci(9))
    fmt.Println("Exponenciacao : ", exponenciacao.Exponenciacao(5, 5))
    fmt.Println("Fatorial : ", fatorial.Fatorial(6))
    fmt.Println("Hanoi : ")
    hanoi.Hanoi(0, 2, 1, 3)
    slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
    fmt.Println("Slice : ", slice)
    fmt.Println("BubbleSort : ", bubblesort.BubbleSort(slice))
    fmt.Println("SelectionSort : ", selectionsort.SelectionSort(slice))
    fmt.Println("InsertionSort : ", insertionsort.InsertionSort(slice))
    fmt.Println("MergeSort : ", mergesort.MergeSort(slice))
}
