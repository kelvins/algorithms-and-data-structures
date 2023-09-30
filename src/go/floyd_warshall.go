package main

import "fmt"



// Algoritmo de Floyd-Warshall
func FloydWarshall(graph [][]int) [][]int {
	// Inicializa a matriz de distancias
	dist := make([][]int, len(graph))
	for i := range dist {
		dist[i] = make([]int, len(graph))
		copy(dist[i], graph[i])
	}

	// Percorre os vértices
	for k := 0; k < len(graph); k++ {
		// Percorre as linhas
		for i := 0; i < len(graph); i++ {
			// Percorre as colunas
			for j := 0; j < len(graph); j++ {
				// Verifica se o caminho passando pelo vértice k é menor
				if dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	return dist
}

var graph = [][]int{
	{0, 5, 999, 10},
	{999, 0, 3, 999},
	{999, 999, 0, 1},
	{999, 999, 999, 0},
}

func main() {
	fmt.Println(FloydWarshall(graph))
}
