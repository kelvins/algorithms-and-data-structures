package main

import (
	"../GoLang/bubblesort"
	"../GoLang/exponenciacao"
	"../GoLang/fatorial"
	"../GoLang/fibonacci"
	"../GoLang/hanoi"
	"../GoLang/heapsort"
	"../GoLang/insertionsort"
	"../GoLang/mergesort"
	"../GoLang/selectionsort"
	"../GoLang/shellsort"
	"fmt"
)

func main() {
	fmt.Println("Fibonacci : ", fibonacci.Fibonacci(9))
	fmt.Println("Exponenciacao : ", exponenciacao.Exponenciacao(5, 5))
	fmt.Println("Fatorial : ", fatorial.Fatorial(6))
	fmt.Println("Hanoi : ")
	hanoi.Hanoi(0, 2, 1, 3)

	slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
	fmt.Println("Slice : ", slice)
  bubblesort.BubbleSort(slice)
	fmt.Println("BubbleSort : ", slice, "\n")

	slice = []int{1, 3, 2, 9, 7, 8, 5, 6, 4}
	fmt.Println("Slice : ", slice)
  selectionsort.SelectionSort(slice)
	fmt.Println("SelectionSort : ", slice, "\n")

	slice = []int{9, 8, 7, 5, 1, 2, 4, 3, 6}
	fmt.Println("Slice : ", slice)
  insertionsort.InsertionSort(slice)
	fmt.Println("InsertionSort : ", slice, "\n")

	slice = []int{4, 6, 7, 1, 2, 3, 5, 9, 8}
	fmt.Println("Slice : ", slice)
  mergesort.MergeSort(slice)
	fmt.Println("MergeSort : ", slice, "\n")

	slice = []int{5, 1, 4, 2, 3, 6, 9, 7, 8}
	fmt.Println("Slice : ", slice)
  shellsort.ShellSort(slice)
	fmt.Println("ShellSort : ", slice, "\n")

	slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
	fmt.Println("Slice : ", slice)
	heapsort.HeapSort1(slice)
	fmt.Println("HeapSort1 : ", slice, "\n")

	slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
	fmt.Println("Slice : ", slice)
	heapsort.HeapSort2(slice)
	fmt.Println("HeapSort2 : ", slice, "\n")
}
