/*
*	Traveling Salesman Problem in C
*	Using a distance matrix to represent an undirected graph.
*	Objective: Find the shortest path that passes through all vertices without repeating any, and return to the starting vertex
*
*                      6
*                 (4)-----(0)
*                 |  \    / \ 
*                 |   \ 3/   \2 
*                 |    \/     \ 
*                3|    /\     (1)
*                 |   / 3\   4/ |
*                 |  /    \  /  |
*                 (3)-----(2)   |
*                  |   7        | 
*                  |            | 3
*                  --------------
*
*
*   Distance Matrix
*       0  1  2  3  4 
*    0  0  2  -  3  6
*    1  2  0  4  3  -
*    2  -  4  0  7  3
*    3  3  3  7  0  3
*    4  6  -  3  3  0
*
*
*/

#include <stdio.h>

#define VERTICES 5
#define INFINITY 429496729

int tempSolution[VERTICES];
int bestSolution[VERTICES];
bool visited[VERTICES];
int bestSolutionValue = INFINITY;
int currentSolutionValue = 0;

int matrix[VERTICES][VERTICES]  = {{         0,          2,   INFINITY, 3,          6 },
								  {          2,          0,          4, 3,   INFINITY },
								  {   INFINITY,          4,          0, 7,          3 },
								  {          3,          3,          7, 0,          3 },
								  {          6,   INFINITY,          3, 3,          0 }};

void travelingSalesmanAux(int x){
	// If the current solution value is already greater than the value of the best solution, stop as it can no longer be the best solution
	if (currentSolutionValue > bestSolutionValue)
		return;

	if (x == VERTICES) { // If x == VERTICES, it means the temporary solution vector is complete
		int distance = matrix[tempSolution[x - 1]][tempSolution[0]];
		// If a better/shorter solution is found
		if (distance < INFINITY && currentSolutionValue + distance < bestSolutionValue) {
			bestSolutionValue = currentSolutionValue + distance; // Replace the best solution with the better one found now
			// Copy the entire temporary solution vector to the vector of the best solution found
			for (int i = 0; i < VERTICES; ++i) {
				bestSolution[i] = tempSolution[i];
			}
		}
		return;
	}

	int last = tempSolution[x - 1]; // Last receives the number of the last vertex in the temporary solution vector
	// Loop that iterates through all columns of the matrix in the row of the last vertex in the temporary solution vector
	for (int i = 0; i < VERTICES; i++) {
		// If position i of the vector has not been visited yet and if the value in the matrix at that position is less than INFINITY
		if (visited[i] == false && matrix[last][i] < INFINITY) {
			visited[i] = true; // Mark it as visited
			tempSolution[x] = i; // Store the vertex currently being processed in the temporary solution vector
			currentSolutionValue += matrix[last][i]; // Increment the value of the matrix in the variable that holds the total distance traveled
			travelingSalesmanAux(x + 1); // Call recursively for the next vertex
			currentSolutionValue -= matrix[last][i]; // If it hasn't finished yet, decrease the value of the variable holding the current solution total
			visited[i] = false; // Set the position to false so it can be used by another vertex
		}
	}

}

void travelingSalesman(int start) {
	visited[start] = true; // Mark the first vertex as visited (0)
	tempSolution[0] = start; // Place vertex 0 in the first position of the temporary solution vector
	travelingSalesmanAux(1); // Call the traveling salesman's auxiliary method
}

void initializeArrays() {
	for (int i = 0; i < VERTICES; i++) {
		visited[i] = false;
		tempSolution[i] = -1;
		bestSolution[i] = -1;
	}
}

int main(){

	initializeArrays();
	travelingSalesman(0);

	printf("Minimum Path: %d\n", bestSolutionValue);
	for (int i = 0; i < VERTICES; i++) {
		printf("%d, ", bestSolution[i]);
	}
	printf("\n\n");
}
