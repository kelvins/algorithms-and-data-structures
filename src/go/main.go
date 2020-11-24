package main

import (
	"fmt"

	"../go/bubblesort"
	"../go/caixeiroviajante"
	"../go/calculatepi"
	"../go/cocktailsort"
	"../go/combsort"
	"../go/countingsort"
	"../go/exponenciacao"
	"../go/fatorial"
	"../go/fibonacci"
	"../go/gnomesort"
	"../go/hanoi"
	"../go/heapsort"
	"../go/insertionsort"
	"../go/mergesort"
	"../go/quicksort"
	"../go/radixsort"
	"../go/selectionsort"
	"../go/shellsort"
)

func main() {
	fmt.Println("Fibonacci : ", fibonacci.Fibonacci(9))
	fmt.Println("Exponenciacao : ", exponenciacao.Exponenciacao(5, 5))
	fmt.Println("Fatorial : ", fatorial.Fatorial(6))
	fmt.Println("Torre de Hanoi : ")
	hanoi.Hanoi(0, 2, 1, 3)

	caixeiroviajante.Run()

	slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
	fmt.Println("Slice : ", slice)
	bubblesort.BubbleSort(slice)
	fmt.Println("BubbleSort : ", slice)

	slice = []int{1, 3, 2, 9, 7, 8, 5, 6, 4}
	fmt.Println("Slice : ", slice)
	selectionsort.SelectionSort(slice)
	fmt.Println("SelectionSort : ", slice)

	slice = []int{9, 8, 7, 5, 1, 2, 4, 3, 6}
	fmt.Println("Slice : ", slice)
	insertionsort.InsertionSort(slice)
	fmt.Println("InsertionSort : ", slice)

	slice = []int{4, 6, 7, 1, 2, 3, 5, 9, 8}
	fmt.Println("Slice : ", slice)
	mergesort.MergeSort(slice)
	fmt.Println("MergeSort : ", slice)

	slice = []int{5, 1, 4, 2, 3, 6, 9, 7, 8}
	fmt.Println("Slice : ", slice)
	shellsort.ShellSort(slice)
	fmt.Println("ShellSort : ", slice)

	slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
	fmt.Println("Slice : ", slice)
	heapsort.HeapSort1(slice)
	fmt.Println("HeapSort1 : ", slice)

	slice = []int{6, 8, 7, 9, 1, 5, 4, 2, 3}
	fmt.Println("Slice : ", slice)
	heapsort.HeapSort2(slice)
	fmt.Println("HeapSort2 : ", slice)

	slice = []int{3, 1, 5, 4, 2, 9, 6, 8, 7}
	fmt.Println("Slice : ", slice)
	radixsort.RadixSort(slice)
	fmt.Println("RadixSort : ", slice)

	slice = []int{2, 1, 8, 4, 3, 7, 6, 5, 9}
	fmt.Println("Slice : ", slice)
	quicksort.QuickSort(slice)
	fmt.Println("QuickSort : ", slice)

	slice = []int{6, 5, 8, 7, 3, 4, 2, 1, 9}
	fmt.Println("Slice : ", slice)
	combsort.CombSort(slice)
	fmt.Println("CombSort : ", slice)

	slice = []int{1, 5, 8, 3, 7, 4, 9, 6, 2}
	fmt.Println("Slice : ", slice)
	cocktailsort.CocktailSort(slice)
	fmt.Println("CocktailSort : ", slice)

	slice = []int{9, 5, 8, 7, 3, 2, 1, 6, 4}
	fmt.Println("Slice : ", slice)
	countingsort.CountingSort(slice)
	fmt.Println("CountingSort : ", slice)

	slice = []int{2, 5, 1, 7, 4, 9, 8, 6, 3}
	fmt.Println("Slice : ", slice)
	gnomesort.GnomeSort(slice)
	fmt.Println("GnomeSort : ", slice)

	slice = []int{10, 1000, 100000, 10000000}
	fmt.Println("Slice : ", slice)
	fmt.Println("CalculatePi : ", calculatepi.CalculatePi(slice))
}
