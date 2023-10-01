/*
 * The Traveling Salesman Problem (TSP) is a problem that seeks to determine
 * the shortest route to visit a series of cities (visiting each one exactly once)
 * and returning to the starting city.
 *
 * It is represented using a distance matrix to depict an undirected graph.
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
const infinito = 99999999

var matrizDistancia [][]int

var tempSolucao []int   // Temporary Solution
var melhorSolucao []int // Best Solution
var visitados []bool    // Visited vertices

var valorMelhorSolucao int
var valorSolucaoAtual int

func CaixeiroViajanteAux(x int) {

// This means it is no longer the best solution; we can stop here.
	if valorSolucaoAtual > valorMelhorSolucao {
		return
	}

	// This means that the temporary solution vector is complete.
	if x == vertices {
		distancia := matrizDistancia[tempSolucao[x-1]][tempSolucao[0]]

		// This means that a better solution has been found.
		if distancia < infinito && (valorSolucaoAtual+distancia) < valorMelhorSolucao {

			// We have found a better solution.
			valorMelhorSolucao = valorSolucaoAtual + distancia

			// Copy the entire vector to the best solution.
			for i := 0; i < vertices; i++ {
				melhorSolucao[i] = tempSolucao[i]
			}
		}
		return
	}

	// Last vertex found in the temporary solution
	ultimo := tempSolucao[x-1]

	// Iterate through all columns of the distance matrix in the row of the last vertex
	for i := 0; i < vertices; i++ {

		// If the position has not been visited yet and the value in the matrix is less than infinity
		if !visitados[i] && matrizDistancia[ultimo][i] < infinito {
			// Mark the position as visited
			visitados[i] = true
			// Load the current vertex into the temporary solution
			tempSolucao[x] = i
			// Increment the total distance traveled based on the matrix position
			valorSolucaoAtual += matrizDistancia[ultimo][i]
			// Call recursively for the next vertex
			CaixeiroViajanteAux(x + 1)
			// If not finished yet, decrement the value of the variable that stores the total distance
			valorSolucaoAtual -= matrizDistancia[ultimo][i]
			// Mark as not visited to be accessed by another vertex
			visitados[i] = false
		}
	}
}

func CaixeiroViajante(posicaoInicial int) {
	// Check if the position is valid
	if posicaoInicial < vertices {
		visitados[posicaoInicial] = true // Mark the first vertex as visited
		tempSolucao[0] = posicaoInicial  // Place the initial position in the first position of the temporary solution
		CaixeiroViajanteAux(1)           // Call the auxiliary method for the traveling salesman
	} else {
		fmt.Println("Vertice inicial invalid")
	}
}

// Initializes the arrays and default values.
func inicia() {

	valorMelhorSolucao = infinito
	valorSolucaoAtual = 0

	for i := 0; i < vertices; i++ {
		visitados = append(visitados, false)
		tempSolucao = append(tempSolucao, -1)
		melhorSolucao = append(melhorSolucao, -1)
	}

	// Creates the distance matrix.
	linha0 := []int{0, 3, 6, 2, 3, infinito}
	linha1 := []int{3, 0, 1, 6, 8, 2}
	linha2 := []int{6, 1, 0, infinito, 4, 5}
	linha3 := []int{2, 6, infinito, 0, 6, 1}
	linha4 := []int{3, 8, 4, 6, 0, 4}
	linha5 := []int{infinito, 2, 5, 1, 4, 0}

	matrizDistancia = append(matrizDistancia, linha0)
	matrizDistancia = append(matrizDistancia, linha1)
	matrizDistancia = append(matrizDistancia, linha2)
	matrizDistancia = append(matrizDistancia, linha3)
	matrizDistancia = append(matrizDistancia, linha4)
	matrizDistancia = append(matrizDistancia, linha5)
}

func main() {
	inicia()
	CaixeiroViajante(0)

	fmt.Println("Caixeiro Viajante")
	fmt.Println("Caminho minimo:", valorMelhorSolucao)
	for i := 0; i < vertices; i++ {
		fmt.Print(melhorSolucao[i], ", ")
	}
	fmt.Println(melhorSolucao[0])
}
