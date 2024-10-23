#include <bits/stdc++.h>

using namespace std;

// Function to display the matrix
void showMatrix(const vector<vector<long>> &matrix, int numVertices) {
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      if (matrix[i][j] < 10) // For better alignment
        cout << " ";
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Floyd-Warshall algorithm
void floydWarshall(vector<vector<long>> &matrix, int n) {
  for (int k = 0; k < n; k++) // Intermediary vertex
  {
    for (int i = 0; i < n; i++) // Origin vertex
    {
      for (int j = 0; j < n; j++) // Destination vertex
      {
        if (matrix[i][k] != LONG_MAX && // i -> k exists
            matrix[k][j] != LONG_MAX && // k -> j exists
            matrix[i][j] >
                matrix[i][k] + matrix[k][j]) // i -> j is shorter via k
        {
          matrix[i][j] = matrix[i][k] + matrix[k][j]; // Update i -> j
        }
      }
    }
  }
}

int main() {
  int numVertices = 5;

  // Initialize matrix with given values
  vector<vector<long>> matrix = {{0, 2, 10, 5, 7},
                                 {2, 0, 3, 3, 1},
                                 {10, 3, 0, 1, 2},
                                 {5, 3, 1, 0, LONG_MAX},
                                 {7, 1, 2, 2, 0}};

  // Display the original matrix
  cout << "Original matrix:" << endl;
  showMatrix(matrix, numVertices);

  // Apply Floyd-Warshall algorithm
  floydWarshall(matrix, numVertices);

  // Display the updated matrix
  cout << "Updated matrix:" << endl;
  showMatrix(matrix, numVertices);

  // Show all shortest paths in 3 columns: source, destination, shortest
  // distance
  cout << "Source\tDestination\tShortest Distance" << endl;
  for (int i = 0; i < numVertices; i++)
    for (int j = 0; j < numVertices; j++)
      cout << i << "\t" << j << "\t\t" << matrix[i][j] << endl;

  return 0;
}
