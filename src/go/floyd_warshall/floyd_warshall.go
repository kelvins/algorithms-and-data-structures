package floydwarshall

// Grafos - Algoritmo de Floyd-Warshall em GO
// Douglas Oliveira - 2022
// https://github.com/xDouglas90
// link Go PlayGround: https://go.dev/play/p/tIRTHkNf7Fz

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
