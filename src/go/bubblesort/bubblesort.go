/* Bubble Sort é um dos algoritmos de ordenação mais simples.
 * A ideia principal é percorrer o vetor/slice várias vezes
 * empurrando/flutuando os valores mais altos para o fim do vetor.
 */
package bubblesort

// Bubble Sort tradicional
func BubbleSort(slice []int) {
	for indice1 := len(slice) - 1; indice1 > 0; indice1-- {
		for indice2 := 0; indice2 < indice1; indice2++ {
			if slice[indice2] > slice[indice2+1] {
				slice[indice2], slice[indice2+1] = slice[indice2+1], slice[indice2]
			}
		}
	}
}

// Bubble Sort recursivo
func Recursivo(slice []int, tamanho int) {
	trocas := 0
	for indice := 0; indice < tamanho-1; indice++ {
		if slice[indice] > slice[indice+1] {
			slice[indice], slice[indice+1] = slice[indice+1], slice[indice]
			trocas++
		}
	}
	if trocas != 0 {
		Recursivo(slice, tamanho-1)
	}
}
