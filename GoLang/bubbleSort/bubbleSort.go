
package bubbleSort

func BubbleSort(vetor []int) ([]int) {
    for indice1 := len(vetor)-1; indice1 > 0; indice1-- {
        for indice2 := 0; indice2 < indice1; indice2++ {
            if vetor[indice2] > vetor[indice2+1] {
                temp := vetor[indice2]
                vetor[indice2] = vetor[indice2+1]
                vetor[indice2+1] = temp
            }
        }
    }
    return vetor
}

func BubbleSortRecursivo(vetor []int, tamanho int) ([]int) {

    trocas := 0
    for indice := 0; indice < tamanho-1; indice++ {
        if vetor[indice] > vetor[indice+1] {
            temp := vetor[indice]
            vetor[indice] = vetor[indice+1]
            vetor[indice+1] = temp
            trocas++
        }
    }

    if trocas != 0 {
        BubbleSortRecursivo(vetor, tamanho-1)
    }

    return vetor
}
