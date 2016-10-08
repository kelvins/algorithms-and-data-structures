
package maximoMinimo

import "fmt"

func MaximoDivisaoEConquista(vetor []int, inicio int, fim int) (int) {
    if inicio == fim {
        return vetor[inicio]
    }

    meio := (inicio+fim)/2
  	aux1 := MaximoDivisaoEConquista(vetor, inicio, meio)
  	aux2 := MaximoDivisaoEConquista(vetor, meio+1, fim)

    if aux1 > aux2 {
        return aux1
    } else {
        return aux2
    }
}

func MinimoMaximoRecursivo(vetor []int, minimo int, maximo int, indice int) {
    if vetor[indice] < minimo {
        minimo = vetor[indice]
    }
    if vetor[indice] > maximo {
        maximo = vetor[indice]
    }
    if indice < len(vetor)-1 {
        MinimoMaximoRecursivo(vetor, minimo, maximo, indice+1)
    } else {
        fmt.Println( "Minimo : ", minimo )
        fmt.Println( "Maximo : ", maximo )
    }
}
