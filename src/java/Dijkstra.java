// Algoritimo de Dijkstra (Dijkstra's Algorithm)
// Anderson Carneiro da Silva
// https://github.com/AndersonSheep

// Baseado no método do GeekforGeeks 
// Um programa Java para o algoritmo de caminho mais curto de fonte única de Dijkstra. 
// O programa é para representação da matriz de adjacência do grafo 

/* Based on the GeekforGeeks method
   A Java program for Dijkstra's single-source shortest path algorithm.
   The program is for the representation of the graph's adjacency matrix */

import java.io.*;
import java.util.*;

class ShortestPath {
  // Uma função de utilidade para encontrar o vértice com valor mínimo de distância,
  // do conjunto de vértices ainda não incluídos na árvore do caminho mais curto
  
  /* A utility function to find the vertex with the minimum distance value,
     from the set of vertices not yet included in the shortest path tree */
  static final int V = 9;

  int minDistance(int dist[], Boolean sptSet[]) {
    // Iniciando um valor minimo
    // Initializing a minimum value
    int min = Integer.MAX_VALUE, min_index = -1;

    for (int v = 0; v < V; v++) {
      if (sptSet[v] == false && dist[v] <= min) {
        min = dist[v];
        min_index = v;
      }
    }

    return min_index;
  }

  // Uma função de utilidade para imprimir a matriz de distância construída
  // A utility function to print the constructed distance matrix
  void printSolution(int dist[]) {
    System.out.println("Vertex \t\t Distance from Source");
    for (int i = 0; i < V; i++) {
      System.out.println(i + " \t\t " + dist[i]);
    }
  }

  // Função que implementa o caminho mais curto da fonte única de Dijkstra
  // algoritmo para um grafo representado usando matriz de adjacência

  /* Function that implements Dijkstra's single-source shortest path algorithm 
     for a graph represented using an adjacency matrix */
  void dijkstra(int graph[][], int src) {
    // A matriz de saída. dist [i] irá manter a menor distância de src a i
    // The output array. dist[i] will hold the shortest distance from src to i
    int dist[] = new int[V];

    // sptSet [i] será verdadeiro se o vértice i for incluído no mais curto
    // árvore do caminho ou distância mais curta de src para i é finalizada

    /* sptSet[i] will be true if vertex i is included in the shortest
       path tree or the shortest distance from src to i is finalized */
    Boolean sptSet[] = new Boolean[V];

    // Inicializa todas as distâncias como INFINITE e stpSet [] como falso
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
      dist[i] = Integer.MAX_VALUE;
      sptSet[i] = false;
    }

    // A distância do vértice de origem é sempre 0
    // The distance of the source vertex is always 0
    dist[src] = 0;

    // Encontre o caminho mais curto para todos os vértices
    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
      // Escolha o vértice de distância mínima do conjunto de vértices
      // ainda não processado. vc é sempre igual a src na primeira iteração.

      /* Pick the vertex with the minimum distance from the set of vertices
         not yet processed. u is always equal to src in the first iteration. */
      int u = minDistance(dist, sptSet);

      // Marque o vértice escolhido como processado
      // Mark the chosen vertex as processed
      sptSet[u] = true;

      // Atualize o valor dist dos vértices adjacentes do vértice escolhido.
      // Update the value dist for the adjacent vertices of the chosen vertex.
      for (int v = 0; v < V; v++)

        // Atualize dist [v] apenas se não estiver em sptSet, há um
        // borda de u a v, e peso total do caminho de src a
        // v a u é menor que o valor atual de dist [v]
        
        /* Update dist[v] only if it's not in sptSet, there is an edge from u to v,
           and the total weight of the path from src to v through u is less than the
           current value of dist[v] */
        if (!sptSet[v]
            && graph[u][v] != 0
            && dist[u] != Integer.MAX_VALUE
            && dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
        }
    }

    // Imprime a matriz de distância construída
    // Print the constructed distance matrix
    printSolution(dist);
  }

  public static void main(String[] args) {
    // Vamos criar o gráfico de exemplo discutido acima
    //Let's create the example graph discussed above
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
