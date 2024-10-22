/*
*	Traveling Salesman Problem in C
*	Using a distance matrix to represent an undirected graph.
*	Objective: Find the shortest path that visits all vertices without repeating any, and returns to the starting vertex.
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
*   Distance Matrix
*       0  1  2  3  4 
*    0  0  2  -  3  6
*    1  2  0  4  3  -
*    2  -  4  0  7  3
*    3  3  3  7  0  3
*    4  6  -  3  3  0
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

void travelingSalesmanAux(int x) {
    // If the current solution value is already greater than the best solution, stop as it can't be the best solution
    if (currentSolutionValue > bestSolutionValue)
        return;

    if (x == VERTICES) { // If x == VERTICES, it means the temporary solution array is complete
        int distance = matrix[tempSolution[x-1]][tempSolution[0]];
        // If a better (shorter) solution is found
        if (distance < INFINITY && currentSolutionValue + distance < bestSolutionValue) {
            bestSolutionValue = currentSolutionValue + distance; // Update the best solution with the new better one
            // Copy the entire temporary solution array to the best solution array
            for (int i = 0; i < VERTICES; ++i) {
                bestSolution[i] = tempSolution[i];
            }
        }
        return;
    }

    int last = tempSolution[x-1]; // 'last' holds the number of the last vertex in the temporary solution array
    // Loop through all columns in the matrix on the row of the last vertex in the temporary solution array
    for (int i = 0; i < VERTICES; i++) {
        // If the i-th vertex hasn't been visited, and the matrix value is less than INFINITY
        if (!visited[i] && matrix[last][i] < INFINITY) {
            visited[i] = true; // Mark as visited
            tempSolution[x] = i; // Add the current vertex to the temporary solution array
            currentSolutionValue += matrix[last][i]; // Increment the path total
            travelingSalesmanAux(x + 1); // Recursively call for the next vertex
            currentSolutionValue -= matrix[last][i]; // Decrease the path total if not finished yet
            visited[i] = false; // Mark the vertex as unvisited so it can be used again by another vertex
        }
    }
}

void travelingSalesman(int start) {
    visited[start] = true; // Mark the starting vertex as visited (0)
    tempSolution[0] = start; // Place vertex 0 in the first position of the temporary solution array
    travelingSalesmanAux(1); // Call the auxiliary function for the traveling salesman problem
}

void initializeArrays() {
    for (int i = 0; i < VERTICES; i++) {
        visited[i] = false;
        tempSolution[i] = -1;
        bestSolution[i] = -1;
    }
}

int main() {
    initializeArrays();
    travelingSalesman(0);

    printf("Minimum path cost: %d\n", bestSolutionValue);
    for (int i = 0; i < VERTICES; i++) {
        printf("%d, ", bestSolution[i]);
    }
    printf("\n\n");
}
