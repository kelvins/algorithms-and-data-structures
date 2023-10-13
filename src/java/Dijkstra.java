// Dijkstra's Algorithm
// Anderson Carneiro da Silva
// https://github.com/AndersonSheep

// Based on the GeekforGeeks method
// A Java program for Dijkstra's single-source shortest path algorithm.
// The program is for the representation of the graph's adjacency matrix.
import java.io.*;
import java.util.*;

class ShortestPath {
  // A utility function to find the vertex with the minimum distance value,
  // from the set of vertices not yet included in the shortest path tree
  static final int V = 9;

  int minDistance(int dist[], Boolean sptSet[]) {
    // Initialize a minimum value
    int min = Integer.MAX_VALUE, min_index = -1;

    for (int v = 0; v < V; v++) {
      if (sptSet[v] == false && dist[v] <= min) {
        min = dist[v];
        min_index = v;
      }
    }

    return min_index;
  }

  // A utility function to print the constructed distance matrix
  void printSolution(int dist[]) {
    System.out.println("Vertex \t\t Distance from Source");
    for (int i = 0; i < V; i++) {
      System.out.println(i + " \t\t " + dist[i]);
    }
  }

  // Function that implements Dijkstra's single-source shortest path algorithm
  // for a graph represented using an adjacency matrix
  void dijkstra(int graph[][], int src) {
    // The output array. dist[i] will hold the shortest distance from src to i
    int dist[] = new int[V];

    // sptSet[i] will be true if vertex i is included in the shortest
    // path tree or the shortest distance from src to i is finalized
    Boolean sptSet[] = new Boolean[V];

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
      dist[i] = Integer.MAX_VALUE;
      sptSet[i] = false;
    }

    // The distance of the source vertex is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
      // Pick the vertex with the minimum distance from the set of vertices
      // not yet processed. u is always equal to src in the first iteration.
      int u = minDistance(dist, sptSet);

      // Mark the chosen vertex as processed
      sptSet[u] = true;

      // Update the value of dist for the adjacent vertices of the chosen vertex
      for (int v = 0; v < V; v++)

        // Update dist[v] only if it's not in sptSet, there is an edge from u to v,
        // and the total weight of the path from src to v through u is less than the
        // current value of dist[v]
        if (!sptSet[v]
            && graph[u][v] != 0
            && dist[u] != Integer.MAX_VALUE
            && dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the constructed distance matrix
    printSolution(dist);
  }

  public static void main(String[] args) {
    // Let's create the example graph discussed above
    int graph[][] =
        new int[][] {
          {0, 4, 0, 0, 0, 0, 0, 8, 0},
          {4, 0, 8, 0, 0, 0, 0, 11, 0},
          {0, 8, 0, 7, 0, 4, 0, 0, 2},
          {0, 0, 7, 0, 9, 14, 0, 0, 0},
          {0, 0, 0, 9, 0, 10, 0, 0, 0},
          {0, 0, 4, 14, 10, 0, 2, 0, 0},
          {0, 0, 0, 0, 0, 2, 0, 1, 6},
          {8, 11, 0, 0, 0, 0, 1, 0, 7},
          {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
    ShortestPath t = new ShortestPath();
    t.dijkstra(graph, 0);
  }
}
