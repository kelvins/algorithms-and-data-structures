/*
 * The Traveling Salesman Problem (TSP) is a problem that tries to determine the
 * shortest route to visit a series of cities (visiting each one only once), returning to the starting city.
 *
 * Using a distance matrix to represent an undirected graph.
 *
 * Assuming we have the following graph:
 *
 *               6
 *      -------------------
 *     |    3         1    |
 *   (000)-----(001)-----(002)
 *     | \     / | \     / |
 *     |  \  6/  |  \2  /  |
 *     |   \ /   |   \ /   |
 *    2|    /   8|    /    |5
 *     |   / \   |   / \   |
 *     |  /  3\  |  /4  \  |
 *     | /     \ | /     \ |
 *   (003)-----(004)-----(005)
 *     |    6         4    |
 *      -------------------
 *               1
 *
 *      Distance Matrix
 *       0  1  2  3  4  5
 *    0  0  3  6  2  3  -
 *    1  3  0  1  6  8  2
 *    2  6  1  0  -  4  5
 *    3  2  6  -  0  6  1
 *    4  3  8  4  6  0  4
 *    5  -  2  5  1  4  0
 *
 * Best solution:
 * 0 - 3 - 5 - 1 - 2 - 4 - 0: 13
 */

package main

import "fmt"

const vertices = 6
const infinity = 99999999

var distanceMatrix [][]int

var tempSolution []int // Temporary solution
var bestSolution []int // Best solution
var visited []bool     // Visited vertices

var bestSolutionValue int
var currentSolutionValue int

func TravelingSalesmanAux(x int) {

	// If the current solution value is greater than the best solution value, it means it's no longer the best solution, so we can stop here
	if currentSolutionValue > bestSolutionValue {
		return
	}

	// If the temporary solution vector is complete
	if x == vertices {
		distance := distanceMatrix[tempSolution[x-1]][tempSolution[0]]

		// If a better solution is found
		if distance < infinity && (currentSolutionValue+distance) < bestSolutionValue {

			// We have a better solution
			bestSolutionValue = currentSolutionValue + distance

			// Copy the entire vector to the best solution
			for i := 0; i < vertices; i++ {
				bestSolution[i] = tempSolution[i]
			}
		}
		return
	}

	// Last vertex in the temporary solution
	last := tempSolution[x-1]

	// Iterate through all columns of the distance matrix in the row of the last vertex
	for i := 0; i < vertices; i++ {

		// If the position has not been visited and the value in the matrix is less than infinity
		if !visited[i] && distanceMatrix[last][i] < infinity {
			// Mark the position as visited
			visited[i] = true
			// Load the current vertex into the temporary solution
			tempSolution[x] = i
			// Increment the total distance traveled based on the position in the matrix
			currentSolutionValue += distanceMatrix[last][i]
			// Call recursively for the next vertex
			TravelingSalesmanAux(x + 1)
			// If it has not finished yet, decrement the value of the variable that stores the total distance
			currentSolutionValue -= distanceMatrix[last][i]
			// Set it as not visited so it can be accessed by another vertex
			visited[i] = false
		}
	}
}

func TravelingSalesman(initialPosition int) {
	// Check if the position is valid
	if initialPosition < vertices {
		visited[initialPosition] = true   // Mark the first vertex as visited
		tempSolution[0] = initialPosition // Put the initial position in the first position of the temporary solution
		TravelingSalesmanAux(1)           // Call the auxiliary method for the traveling salesman
	} else {
		fmt.Println("Invalid initial vertex")
	}
}

// Initialize vectors and default values
func initialize() {

	bestSolutionValue = infinity
	currentSolutionValue = 0

	for i := 0; i < vertices; i++ {
		visited = append(visited, false)
		tempSolution = append(tempSolution, -1)
		bestSolution = append(bestSolution, -1)
	}

	// Create the distance matrix
	row0 := []int{0, 3, 6, 2, 3, infinity}
	row1 := []int{3, 0, 1, 6, 8, 2}
	row2 := []int{6, 1, 0, infinity, 4, 5}
	row3 := []int{2, 6, infinity, 0, 6, 1}
	row4 := []int{3, 8, 4, 6, 0, 4}
	row5 := []int{infinity, 2, 5, 1, 4, 0}

	distanceMatrix = append(distanceMatrix, row0)
	distanceMatrix = append(distanceMatrix, row1)
	distanceMatrix = append(distanceMatrix, row2)
	distanceMatrix = append(distanceMatrix, row3)
	distanceMatrix = append(distanceMatrix, row4)
	distanceMatrix = append(distanceMatrix, row5)
}

func main() {
	initialize()
	TravelingSalesman(0)

	fmt.Println("Traveling Salesman")
	fmt.Println("Minimum path:", bestSolutionValue)
	for i := 0; i < vertices; i++ {
		fmt.Print(bestSolution[i], ", ")
	}
	fmt.Println(bestSolution[0])
}
