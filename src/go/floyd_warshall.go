package main

import "fmt"

// Graphs - Floyd-Warshall Algorithm in GO
// Go PlayGround link: https://go.dev/play/p/tIRTHkNf7Fz

// Floyd-Warshall Algorithm
func FloydWarshall(graph [][]int) [][]int {
	// Initialize the distance matrix
	dist := make([][]int, len(graph))
	for i := range dist {
		dist[i] = make([]int, len(graph))
		copy(dist[i], graph[i])
	}

	// Traverse the vertices
	for k := 0; k < len(graph); k++ {
		// Traverse the rows
		for i := 0; i < len(graph); i++ {
			// Traverse the columns
			for j := 0; j < len(graph); j++ {
				// Check if the path passing through vertex k is shorter
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
