
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
    "../GoLang/shellsort"
    "../GoLang/heapsort"
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

    slice = []int{1, 3, 2, 9, 7, 8, 5, 6, 4}
    fmt.Println("Slice : ", slice)
    fmt.Println("SelectionSort : ", selectionsort.SelectionSort(slice))

    slice = []int{9, 8, 7, 5, 1, 2, 4, 3, 6}
    fmt.Println("Slice : ", slice)
    fmt.Println("InsertionSort : ", insertionsort.InsertionSort(slice))

    slice = []int{4, 6, 7, 1, 2, 3, 5, 9, 8}
    fmt.Println("Slice : ", slice)
    fmt.Println("MergeSort : ", mergesort.MergeSort(slice))

    slice = []int{5, 1, 4, 2, 3, 6, 9, 7, 8}
    fmt.Println("Slice : ", slice)
    fmt.Println("ShellSort : ", shellsort.ShellSort(slice))

    slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
    fmt.Println("Slice : ", slice)
    fmt.Println("HeapSort1 : ", heapsort.HeapSort1(slice))

    slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
    fmt.Println("Slice : ", slice)
    fmt.Println("HeapSort2 : ", heapsort.HeapSort2(slice))
}
