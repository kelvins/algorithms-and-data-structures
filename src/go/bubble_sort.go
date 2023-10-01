package main

import "fmt"

// Iterative Approach
func BubbleSortIterativo(slice []int) {
    for indice1 := len(slice) - 1; indice1 > 0; indice1-- {
        for indice2 := 0; indice2 < indice1; indice2++ {
            // Swap if the current element is greater than the next element
            if slice[indice2] > slice[indice2+1] {
                slice[indice2], slice[indice2+1] = slice[indice2+1], slice[indice2]
            }
        }
    }
}

// Recursive Approach
func BubbleSortRecursivo(slice []int, tamanho int) {
    trocas := 0
    for indice := 0; indice < tamanho-1; indice++ {
        // Swap if the current element is greater than the next element
        if slice[indice] > slice[indice+1] {
            slice[indice], slice[indice+1] = slice[indice+1], slice[indice]
            trocas++
        }
    }
    if trocas != 0 {
        BubbleSortRecursivo(slice, tamanho-1)
    }
}

func main() {
    slice := []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
    fmt.Println("Slice:", slice)
    
    // Sort the slice using the iterative Bubble Sort
    BubbleSortIterativo(slice)
    fmt.Println("BubbleSort (Iterative):", slice)
    
    // Reinitialize the slice for the recursive Bubble Sort
    slice = []int{5, 2, 1, 6, 9, 8, 7, 3, 4}
    
    // Sort the slice using the recursive Bubble Sort
    BubbleSortRecursivo(slice, len(slice))
    fmt.Println("BubbleSort (Recursive):", slice)
}
