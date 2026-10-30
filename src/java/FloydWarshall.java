/*
 * Floyd-Warshall algorithm in Java
 * All pairs shortest path algorithm
 * Time Complexity:  O(n³)
 * Space Complexity: O(n²)
 */

public class FloydWarshall {

  public static void showMatrix(long[][] matrix, int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
      for (int j = 0; j < vertexCount; j++) {
        if (matrix[i][j] < 10) {
          System.out.print(" " + matrix[i][j] + " ");
        } else {
          System.out.print(matrix[i][j] + " ");
        }
      }

      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    int vertexCount = 5;
    long[][] matrix = {
      {0, 2, 10, 5, 7},
      {2, 0, 3, 3, 1},
      {10, 3, 0, 1, 2},
      {5, 3, 1, 0, Long.MAX_VALUE},
      {7, 1, 2, 2, 0}
    };

    // Display the original matrix
    System.out.println("Original matrix:");
    showMatrix(matrix, vertexCount);

    floydWarshall(matrix, vertexCount);

    // Display the updated matrix
    System.out.println("Updated matrix:");
    showMatrix(matrix, vertexCount);

    // Show all shortest paths
    System.out.println();
    for (int i = 0; i < vertexCount; i++) {
      for (int x = 0; x < vertexCount; x++) {
        System.out.println("Shortest distance from " + i + " to " + x + " = " + matrix[x][i] + ".");
      }
    }
    System.out.println();
  }

  public static void floydWarshall(long[][] matrix, int n) {
    for (int x = 0; x < n; x++) { // Intermediary vertex
      for (int y = 0; y < n; y++) { // Origin vertex
        for (int z = 0; z < n; z++) { // Destination vertex
          if (matrix[y][z] > (matrix[y][x] + matrix[x][z])) {
            matrix[y][z] = matrix[y][x] + matrix[x][z];
          }
        }
      }
    }
  }
}
