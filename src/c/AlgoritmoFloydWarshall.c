/*
*   Graphs - Floyd-Warshall Algorithm in C
*   Kelvin Salton do Prado - 2015
*   Complexity: Theta of vertices cubed = Theta(n^3)
*
*   Finds the path from all vertices to all vertices
*
*   Graph with 5 vertices and 6 edges
*
*              6
*   (0)-----------------(1)
*    |                   |
* 10 |                   | 2
*    |         1         |
*   (2)-----------------(3)
*     \                 /
*   3  \               / 8
*      \             /
*       -----(4)-----
*
*   Distance Matrix
*       0   1   2   3   4
*   0   0   6  10   -   -
*   1   6   0   -   2   -
*   2  10   -   0   1   3
*   3   -   2   1   0   8
*   4   -   -   3   8   0
*
*   Infinity values are considered as 4294967295
*
*/

#include <stdio.h>

#define nroVertices 5 // Defines a constant 5, which is the number of vertices in the graph

// The Floyd-Warshall algorithm takes the distance matrix and the number of vertices as parameters
void FloydWarshall(unsigned long int matrix[nroVertices][nroVertices], int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int z = 0; z < n; z++){
                if( matrix[y][z] > (matrix[y][x] + matrix[x][z]) )
                    matrix[y][z] = matrix[y][x] + matrix[x][z];
            }   
        }   
    }
}

int main(){

    unsigned long int Matrix[nroVertices][nroVertices] = {{         0,          6,         10, 4294967295, 4294967295 },
                                                         {          6,          0, 4294967295,          2, 4294967295 },
                                                         {         10, 4294967295,          0,          1,          3 },
                                                         { 4294967295,          2,          1,          0,          8 },
                                                         { 4294967295, 4294967295,          3,          8,          0 }};

    FloydWarshall(Matrix, nroVertices);

    // Display the matrix with updated values
    printf("Matrix:\n");
    for (int i = 0; i < nroVertices; ++i){
        for (int e = 0; e < nroVertices; ++e){
            if( Matrix[i][e] < 10 )
                printf(" %lu ", Matrix[i][e]);
            else
                printf("%lu ", Matrix[i][e]);
        }
        printf("\n");
    }
    printf("\n");

    // printf("Shortest path total from vertex 0 to 4: %lu\n", Matrix[4][0]); // [destination] [source]
    // printf("Shortest path total from vertex 2 to 0: %lu\n", Matrix[0][2]);
    // printf("Shortest path total from vertex 4 to 3: %lu\n\n", Matrix[3][4]);

    // Display all paths
    printf("\n");
    for (int i = 0; i < nroVertices; ++i){
        for (int x = 0; x < nroVertices; ++x){
            printf("Shortest distance from %d to %d = %lu.\n", i, x, Matrix[x][i]);
        }
    }
    printf("\n\n");

    return 0;
}
