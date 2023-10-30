/*
 * Floyd-Warshall algorithm in Java
 * All pairs shortest path algorithm
 * Time Complexity:  O(n³)
 * Space Complexity: O(n²)
*/

public class FloydWarshall {

  public static void showMatrix(long[][] matriz, int nroVertices) {
    for (int i = 0; i < nroVertices; i++) {
      for (int j = 0; j < nroVertices; j++) {
        if (matriz[i][j] < 10) {
          System.out.print(" " + matriz[i][j] + " ");
        } else {
          System.out.print(matriz[i][j] + " ");
        }
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    int nroVertices = 5;
    long[][] matriz = {
      {0, 2, 10, 5, 7},
      {2, 0, 3, 3, 1},
      {10, 3, 0, 1, 2},
      {5, 3, 1, 0, Long.MAX_VALUE},
      {7, 1, 2, 2, 0}
    };

    // Display the original matrix
    System.out.println("Original matrix:");
    showMatrix(matriz, nroVertices);

    floydWarshall(matriz, nroVertices);

    // Display the updated matrix
    System.out.println("Updated matrix:");
    showMatrix(matriz, nroVertices);

    // Show all shortest paths
    System.out.println();
    for (int i = 0; i < nroVertices; i++) {
      for (int x = 0; x < nroVertices; x++) {
        System.out.println("Shortest distance from " + i + " to " + x + " = " + matriz[x][i] + ".");
      }
    }
    System.out.println();
  }

  public static void floydWarshall(long[][] matriz, int n) {
    for (int x = 0; x < n; x++) { // Intermediary vertex
      for (int y = 0; y < n; y++) { // Origin vertex
        for (int z = 0; z < n; z++) { // Destination vertex
          if (matriz[y][z] > (matriz[y][x] + matriz[x][z])) {
            matriz[y][z] = matriz[y][x] + matriz[x][z];
          }
        }
      }
    }
  }
}