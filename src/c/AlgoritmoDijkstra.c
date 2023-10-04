/*
* Graphs - Dijkstra Algorithm in C
* Kelvin Salton do Prado - 2015
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
*  Matriz de Distância
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
* For infinite values the value will be considered: 4294967295
* The objective is to leave the starting point (0) and reach the destination (4) by the shortest route
* Answer: (0)->(1)->(3)->(2)->(4) = 12
*
*/

#include <stdio.h>

#define nroVertices 5 // Defines a constant 5 which is the number of vertices in the graph

// Dijkstra's algorithm takes as parameters the distance matrix and the number of vertices
void Dijkstra(unsigned long int matriz[nroVertices][nroVertices], int n){
    bool visitados[n]; // Variable that holds true for visited vertices

    // The 'i' value of the for below is not used, as the for is only used to traverse the entire number of columns in the matrix
    for(int i = 1; i < n; i++){ // It starts at 1 because it does not need to compare the vertex with itself

        int min = -1; // Variable that stores the position of the lowest value, starts at -1 as it is an invalid position
        unsigned long int MinValor = 4294967295; // Variable that stores the smallest value found, starts with 'infinity', so always on the first pass the value will be smaller than this variable

        // For that traverses all rows in column [0]
        for(int j = 1; j < n; j++){
            // If the vertex has not yet been visited and the value is less than the 'MinValor'
            if( !visitados[j] && matriz[j][0] < MinValor ){
                   min = j; // Saves the position of the smallest
                   MinValor = matriz[j][0]; // Keep the lowest value
            }
          }

          visitados[min] = true; // Mark the value of the minimum position as visited

        // For de 1 até n
          for(int j = 1; j < n; j++){
               // If the value of column [0] + the value of the passing column is less than the value of the passing row and column [0]
               // Updates the first column of the matrix, which will be used for the next iterations
               if( (matriz[min][0] + matriz[min][j]) < matriz[j][0] ){
                matriz[j][0] = matriz[min][0] + matriz[min][j];
               }
          }
    }
}

int main(){

    unsigned long int Matriz[nroVertices][nroVertices] = {{          0,          6,         10, 4294967295, 4294967295 },
                                                          {          6,          0, 4294967295,          2, 4294967295 },
                                                          {         10, 4294967295,          0,          1,          3 },
                                                          { 4294967295,          2,          1,          0,          8 },
                                                          { 4294967295, 4294967295,          3,          8,          0 }};

    Dijkstra(Matriz, nroVertices);

    printf("Shortest path from vertex 0 to 4: %lu\n", Matriz[4][0]); // Shortest total path

    // Print the matrix with the updated values
    printf("Matriz:\n");
    for (int i = 0; i < nroVertices; ++i){
        for (int e = 0; e < nroVertices; ++e){
            if( Matriz[i][e] < 10 )
                printf(" %lu ", Matriz[i][e]);
            else
                printf("%lu ", Matriz[i][e]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
