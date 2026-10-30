/*
 *	Graphs - Floyd-Warshall Algorithm in C
 *	Complexity: Theta of vertices cubed = Theta(n^3)
 *
 *	Finds the path from all to all vertices
 *
 *	Graph with 5 vertices and 6 edges
 *
 *			   6
 *	(0)-----------------(1)
 *	 |					 |
 * 10 |					 | 2
 *	 |		   1		 |
 *	(2)-----------------(3)
 *	  \					/
 *	 3 \			   / 8
 *		\			  /
 *		 -----(4)-----
 *
 *	 Distance matrix
 *	   0   1   2   3   4
 *	0  0   6  10   -   -
 *	1  6   0   -   2   -
 *	2 10   -   0   1   3
 *	3  -   2   1   0   8
 *	4  -   -   3   8   0
 *
 * 	The value 4294967295 represents infinity
 *
 */

#include <stdio.h>

#define vertexCount 5 // Define the constant 5 as the number of graph vertices

// The Floyd-Warshall algorithm receives the distance matrix and the number
// of vertices
void floydWarshall(unsigned long int matrix[vertexCount][vertexCount], int n) {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int z = 0; z < n; z++) {
        if (matrix[y][z] > (matrix[y][x] + matrix[x][z]))
          matrix[y][z] = matrix[y][x] + matrix[x][z];
      }
    }
  }
}

int main() {

  unsigned long int matrix[vertexCount][vertexCount] = {
      {0, 6, 10, 4294967295, 4294967295},
      {6, 0, 4294967295, 2, 4294967295},
      {10, 4294967295, 0, 1, 3},
      {4294967295, 2, 1, 0, 8},
      {4294967295, 4294967295, 3, 8, 0}};

  floydWarshall(matrix, vertexCount);

  // Display the matrix with updated values
  printf("Matrix:\n");
  for (int i = 0; i < vertexCount; ++i) {
    for (int e = 0; e < vertexCount; ++e) {
      if (matrix[i][e] < 10)
        printf(" %lu ", matrix[i][e]);
      else
        printf("%lu ", matrix[i][e]);
    }
    printf("\n");
  }
  printf("\n");

  // printf("Total shortest path from vertex 0 to vertex 4: %lu\n",
  // Matrix[4][0]);
  // // [destination] [source] printf("Shortest path distance from vertex 2 to
  // 0: %lu\n", Matrix[0][2]); printf("Shortest path distance from vertex 4 to
  // 3: %lu\n\n", Matrix[3][4]);

  // Display all paths
  printf("\n");
  for (int i = 0; i < vertexCount; ++i) {
    for (int x = 0; x < vertexCount; ++x) {
      printf("Shortest distance from vertex %d to vertex %d = %lu.\n", i, x,
             matrix[x][i]);
    }
  }
  printf("\n\n");

  return 0;
}