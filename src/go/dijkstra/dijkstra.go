/*
* Grafos - Algoritmo de Dijkstra em Go
* Danilo Moura - 2020
* Complexidade: Teta(n^2)
* Implementação utilizando matriz de adjacências (matriz de distância)
* 
* 1 para todos - Arestas de pesos não negativo - Algoritmo guloso
* Encontra o caminho mais curto de um vértice (inicio) a outro (destino)
*
* Grafo com 5 vértices e 6 arestas
*
*              6
*   (0)-----------------(1)
*    |                   |
* 10 |                   | 2
*    |         1         |
*   (2)-----------------(3)
*    \                  /
*   3 \                / 8
*      \              /
*       -----(4)-----
*
* Matriz de Distância
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
* O objetivo é sair do ponto inicial (0) e chegar ao destino (4) pelo caminho mais curto
* Resposta: (0)->(1)->(3)->(2)->(4) = 12
*
* link Go PlayGround: https://play.golang.org/p/HyWAcYJ3qXY
*/

package main

import (
	"fmt"
)

var nroVertices int = 5
type Matriz [][]int
var maxInt = 4294967295

// Algoritmo de Dijkstra recebe como parâmetro a matriz de distância e o número de vértices
func Dijkstra(matriz Matriz, n int) {
	visitados := make([]bool, n) // Variável que guarda true para os vértices visitados
	// O valor 'i' do for abaixo não é utilizado, pois o for serve apenas para percorrer todo o número de colunas da matriz
	for i := 1; i < n; i++ { // Começa em 1 pois não precisa comparar o vértice com ele mesmo

		min := -1          // Variável que guarda a posição do menor valor, inicia em -1 pois é uma posição inválida
		minValor := maxInt // Variável que guarda o menor valor encontrado, inicia com 'infinito', assim, sempre na primeira passada o valor será menor que esta variável

		// For que percorre todas as linhas na coluna [0]
		for j := 1; j < n; j++ {
			// Se o vertice ainda não foi visitado e o valor for menor que o 'MinValor'
			if !visitados[j] && matriz[j][0] < minValor {
				min = j                 // Guarda a posição do menor
				minValor = matriz[j][0] // Guarda o menor valor
			}
		}

		visitados[min] = true // Marca o valor a posição do minimo como visitado

		// For de 1 até n
		for j := 1; j < n; j++ {
			// Se o valor da coluna [0] + o valor da coluna que está passando for menor que o valor da linha que está passando e coluna [0]
			// Atualiza a primeira coluna da matriz, que será utilizado para as próximas iterações
			if (matriz[min][0] + matriz[min][j]) < matriz[j][0] {
				matriz[j][0] = matriz[min][0] + matriz[min][j]
			}
		}
	}
}

func main() {
	matriz := Matriz{
		{      0,      6,     10, maxInt, maxInt },
		{      6,      0, maxInt,      2, maxInt },
		{     10, maxInt,      0,      1,      3 },
		{ maxInt,      2,      1,      0,      8 },
		{ maxInt, maxInt,      3,      8,      0 },
	}

	Dijkstra(matriz, nroVertices)

	fmt.Printf("Total caminho mais curto do vertice 0 ao 4: %v\n\n", matriz[4][0]) // Caminho total mais curto

	// Da print na matriz com os valores atualizados
	fmt.Println("Matriz:")

	fmt.Printf("-  |	|v0	|v1	|v2	|v3	|v4\n")
	fmt.Println("_____________________________________________")

	for i := 0; i < nroVertices; i++ {
		for j := 0; j < nroVertices; j++ {

			if j == 0 {
				fmt.Printf("v%v |", i)
			}

			if matriz[i][j] == maxInt {
				fmt.Printf("	|inf")
			} else {
				fmt.Printf("	|%v", matriz[i][j])
			}
		}
		fmt.Println()
	}
	fmt.Println()
}