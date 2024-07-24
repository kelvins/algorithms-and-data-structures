/*
* Graphs - Dijkstra's Algorithm in Go
* Complexity: Theta(n^2)
* Implementation using adjacency matrix (distance matrix)
*
* One to all - Non-negative weighted edges - Greedy algorithm
* Finds the shortest path from one vertex (start) to another (destination)
*
* Graph with 5 vertices and 6 edges
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
* Distance Matrix
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
* The goal is to start from the initial point (0) and reach the destination (4) by the shortest path
* Answer: (0)->(1)->(3)->(2)->(4) = 12
*
* Go PlayGround link: https://play.golang.org/p/HyWAcYJ3qXY
 */

package main

import "fmt"

var nroVertices = 5

type Matrix [][]int

var maxInt = 4294967295

// Dijkstra's Algorithm takes the distance matrix and the number of vertices as parameters
func Dijkstra(matrix Matrix, n int) {
	visited := make([]bool, n) // Variable that stores true for visited vertices
	// The 'i' value in the for loop below is not used, as the loop is only used to iterate over the number of columns in the matrix
	for i := 1; i < n; i++ { // Starts at 1 because there is no need to compare the vertex with itself

		min := -1          // Variable that stores the position of the smallest value, starts at -1 because it is an invalid position
		minValue := maxInt // Variable that stores the smallest value found, starts with 'infinity', so in the first pass the value will be smaller than this variable

		// For loop that iterates over all rows in column [0]
		for j := 1; j < n; j++ {
			// If the vertex has not been visited yet and the value is smaller than 'minValue'
			if !visited[j] && matrix[j][0] < minValue {
				min = j                 // Stores the position of the smallest value
				minValue = matrix[j][0] // Stores the smallest value
			}
		}

		visited[min] = true // Marks the position of the minimum as visited

		// For loop from 1 to n
		for j := 1; j < n; j++ {
			// If the value of column [0] + the value of the current column is smaller than the value of the current row and column [0]
			// Updates the first column of the matrix, which will be used for the next iterations
			if (matrix[min][0] + matrix[min][j]) < matrix[j][0] {
				matrix[j][0] = matrix[min][0] + matrix[min][j]
			}
		}
	}
}

func main() {
	matrix := Matrix{
		{0, 6, 10, maxInt, maxInt},
		{6, 0, maxInt, 2, maxInt},
		{10, maxInt, 0, 1, 3},
		{maxInt, 2, 1, 0, 8},
		{maxInt, maxInt, 3, 8, 0},
	}

	Dijkstra(matrix, nroVertices)

	fmt.Printf("Total shortest path from vertex 0 to 4: %v\n\n", matrix[4][0]) // Total shortest path

	// Prints the matrix with the updated values
	fmt.Println("Matrix:")

	fmt.Printf("-  |	|v0	|v1	|v2	|v3	|v4\n")
	fmt.Println("_____________________________________________")

	for i := 0; i < nroVertices; i++ {
		for j := 0; j < nroVertices; j++ {

			if j == 0 {
				fmt.Printf("v%v |", i)
			}

			if matrix[i][j] == maxInt {
				fmt.Printf("	|inf")
			} else {
				fmt.Printf("	|%v", matrix[i][j])
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
