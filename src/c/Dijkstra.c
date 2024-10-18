/*
* Graphs - Dijkstra Algorithm in C
* Complexity: Theta(n^2)
*
* 1 for all - Edges with non-negative weights - Greedy algorithm
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
*  Distance Matrix
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
*  For infinite values, the value will be considered: 4294967295
* The objective is to leave the starting point (0) and reach the destination (4) by the shortest route
* Response: (0)->(1)->(3)->(2)->(4) = 12
*
*/

#include <stdio.h>
#include <stdbool.h>

#define noVertices 5 // Defines a constant 5 which is the number of vertices in the graph

// Dijkstra's algorithm takes as parameters the distance matrix and the number of vertices
void Dijkstra(unsigned long int matrix[noVertices][noVertices], int n){
    
bool visited[n]; // Variable that holds true for visited vertices

    // The value 'i' from the for below is not used, as the for is only used to traverse the entire number of columns in the matrix
    for(int i = 1; i < n; i++){ // Starts at 1 because you don't need to compare the vertex with itself

int min = -1; // Variable that stores the position of the smallest value, starts at -1 as it is an invalid position
        unsigned long int MinValue = 4294967295; // Variable that stores the smallest value found, starts with 'infinity', so always on the first pass the value will be smaller than this variable
        // For that loops through all rows in column [0]
        for(int j = 1; j < n; j++){
            // If the vertex has not yet been visited and the value is less than the 'MinValor'
            if( !visited[j] && matrix[j][0] < MinValue ){
                   min = j; // Saves the position of the smallest
                   MinValue = matrix[j][0]; // Save the smallest value
            }
          }

          visited[min] = true; // Mark the value of the minimum position as visited

        // Goes from 1 to n
          for(int j = 1; j < n; j++){
               // If the value of column [0] + the value of the passing column is less than the value of the passing row and column [0]
               // Update the first column of the matrix, which will be used for the next iterations
               if( (matrix[min][0] + matrix[min][j]) < matrix[j][0] ){
                matrix[j][0] = matrix[min][0] + matrix[min][j];
               }
          }
    }
}

int main(){

    unsigned long int Matrix[noVertices][noVertices] = {{          0,          6,         10, 4294967295, 4294967295 },
                                                          {          6,          0, 4294967295,          2, 4294967295 },
                                                          {         10, 4294967295,          0,          1,          3 },
                                                          { 4294967295,          2,          1,          0,          8 },
                                                          { 4294967295, 4294967295,          3,          8,          0 }};

    Dijkstra(Matrix, noVertices);

    printf("Total shortest path from vertex 0 to 4: %lu\n", Matrix[4][0]); // Shortest total path

    // Print the matrix with the updated values
    printf("Matrix:\n");
    for (int i = 0; i < noVertices; ++i){
        for (int e = 0; e < noVertices; ++e){
            if( Matrix[i][e] < 10 )
                printf(" %lu ", Matrix[i][e]);
            else
                printf("%lu ", Matrix[i][e]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

//  In English 
/*
* Graphs - Dijkstra Algorithm in C
* Complexity: Theta(n^2)
*
* 1 for all - Edges with non-negative weights - Greedy algorithm
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
*  Distance Matrix
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
*  For infinite values, the value will be considered: 4294967295
* The objective is to leave the starting point (0) and reach the destination (4) by the shortest route
* Response: (0)->(1)->(3)->(2)->(4) = 12
*
*/

// #define NUM_VERTICES 5 // Number of vertices in the graph

// // Dijkstra's algorithm takes as parameters the distance matrix and the number of vertices
// void Dijkstra(unsigned long int distanceMatrix[NUM_VERTICES][NUM_VERTICES], int numVertices) {
//     bool visited[numVertices]; // Array to track visited vertices
//     // Initialize visited vertices to false
//     for (int i = 0; i < numVertices; i++) {
//         visited[i] = false;
//     }

//     // Start from the first vertex (0)
//     for (int i = 1; i < numVertices; i++) { // Loop through each vertex
//         int minIndex = -1; // Initialize the index of the minimum value
//         unsigned long int minValue = 4294967295; // Start with "infinity"

//         // Find the unvisited vertex with the smallest distance
//         for (int j = 1; j < numVertices; j++) {
//             if (!visited[j] && distanceMatrix[j][0] < minValue) {
//                 minIndex = j; // Update the index of the minimum value
//                 minValue = distanceMatrix[j][0]; // Update the minimum value
//             }
//         }

//         visited[minIndex] = true; // Mark the vertex with the smallest distance as visited

//         // Update the distances for the neighboring vertices
//         for (int j = 1; j < numVertices; j++) {
//             // If a shorter path to j is found through minIndex
//             if ((distanceMatrix[minIndex][0] + distanceMatrix[minIndex][j]) < distanceMatrix[j][0]) {
//                 distanceMatrix[j][0] = distanceMatrix[minIndex][0] + distanceMatrix[minIndex][j]; // Update distance
//             }
//         }
//     }
// }

// int main() {
//     // Distance matrix representation of the graph
//     unsigned long int distanceMatrix[NUM_VERTICES][NUM_VERTICES] = {
//         {0, 6, 10, 4294967295, 4294967295},
//         {6, 0, 4294967295, 2, 4294967295},
//         {10, 4294967295, 0, 1, 3},
//         {4294967295, 2, 1, 0, 8},
//         {4294967295, 4294967295, 3, 8, 0}
//     };

//     Dijkstra(distanceMatrix, NUM_VERTICES); // Call Dijkstra's algorithm

//     printf("Total shortest path from vertex 0 to 4: %lu\n", distanceMatrix[4][0]); // Shortest total path

//     // Print the updated distance matrix
//     printf("Updated Distance Matrix:\n");
//     for (int i = 0; i < NUM_VERTICES; ++i) {
//         for (int j = 0; j < NUM_VERTICES; ++j) {
//             if (distanceMatrix[i][j] < 10)
//                 printf(" %lu ", distanceMatrix[i][j]); // Print formatted distance
//             else
//                 printf("%lu ", distanceMatrix[i][j]); // Print formatted distance
//         }
//         printf("\n");
//     }
//     printf("\n");

//     return 0;
// }
