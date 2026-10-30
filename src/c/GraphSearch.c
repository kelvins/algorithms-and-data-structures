/*
 *
 *	Graphs - Implementation of an Undirected Graph structure in C
 *	Search Methods: Depth-First Search and Breadth-First Search
 *
 *
 *   (A)---------------(B)-------------(E)---------------(F)
 *    |                 |               |                 |
 *    |                 |               |                 |
 *    |                 |               |                 |
 *   (C)---------------(D)---------------                 |
 *                      |                                 |
 *                      -----------------------------------
 *
 *	6 Vertices
 *	8 Edges
 */

#include <malloc.h>
#include <stdio.h>

#define MAX_VERTICES                                                           \
  6 // MAXIMUM NUMBER OF GRAPH VERTICES; update this value if the graph changes
    // The vertex limit is six for the graph shown above.
#define MAX_ARESTAS                                                            \
  (MAX_VERTICES *                                                              \
   (MAX_VERTICES -                                                             \
    1)) // CALCULATE THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// Structure defining each graph vertex
typedef struct NO {
  char id;
  int nroVizinhos;
  struct NO *vizinhos[MAX_ARESTAS];
  bool visitado;
} *VERTICE;

// Create and return a vertex
VERTICE criaVertice(char id) {
  VERTICE novoVertice = (VERTICE)malloc(sizeof(NO)); // Allocate a new vertex
  novoVertice->id = id;
  novoVertice->nroVizinhos = 0;
  novoVertice->visitado = false;
  for (int i = 0; i < MAX_ARESTAS; i++) {
    novoVertice->vizinhos[i] = NULL;
  }
  return novoVertice;
}

// Connect the vertices passed as parameters
bool ligaVertices(VERTICE v1, VERTICE v2) {
  int aux = 0;
  while (v1->vizinhos[aux] !=
         NULL) { // Find the first empty (NULL) neighbor slot
    aux++;
  }
  v1->vizinhos[aux] = v2; // Add the new neighbor to the neighbor list
  aux = 0;
  while (v2->vizinhos[aux] !=
         NULL) { // Find the first empty (NULL) neighbor slot
    aux++;
  }
  v2->vizinhos[aux] = v1; // Add the new neighbor to the neighbor list
  v1->nroVizinhos++;      // Increment the number of neighbors
  v2->nroVizinhos++;      // Increment the number of neighbors
}

/*
 *	Depth-First Search (DFS)
 *	Visit neighbors in the order they were connected to the vertex.
 *
 */
int buscaEmProfundidade(VERTICE inicio, VERTICE destino, int visitados) {
  inicio->visitado = true; // Mark the current vertex as visited
  if (inicio == destino)
    return visitados; // If this is the destination, return the distance

  int aux = 0;
  while (inicio->vizinhos[aux] != NULL) { // While there are neighbors to visit
    if (inicio->vizinhos[aux]->visitado ==
        false) { // If the neighbor has not been visited
      // Recurse from the new neighbor, visiting all of its neighbors in turn
      int resposta =
          buscaEmProfundidade(inicio->vizinhos[aux], destino, visitados + 1);
      // If the result is greater than -1, the destination was found; return it
      if (resposta != -1)
        return resposta;
    }
    aux++; // Advance to the next neighbor
  }

  return -1; // The vertex was not found
}

/*
 *	Breadth-First Search (BFS)
 *	Implemented as a queue using a simple array
 *	Instead of removing a vertex from the array, it advances one position
 *and visits all vertices by level
 */
int buscaEmLargura(VERTICE inicio, VERTICE destino) {
  int iniFila = 0; // Queue position, used to control the while loop
  int tamFila = 1; // Queue size

  VERTICE
  FILA[MAX_VERTICES]; // Queue holding the vertices to compare
  for (int i = 0; i < MAX_VERTICES;
       i++) { // Clear the array first because it is not dynamically allocated
    FILA[i] = NULL;
  }
  FILA[iniFila] = inicio; // Store the starting vertex at queue position 0

  // Process the queue until it is empty
  while (iniFila < tamFila) {
    // If the next element is the destination, return the distance (iniFila)
    if (FILA[iniFila] == destino)
      return iniFila;

    /*
     *	For each neighbor of the vertex at the front of the queue:
     *	Mark each as visited so it is not added to the queue again,
     *	then enqueue it and increase the queue size
     */
    for (int i = 0; i < FILA[iniFila]->nroVizinhos; i++) {
      if (FILA[iniFila]->vizinhos[i]->visitado == false) {
        FILA[iniFila]->vizinhos[i]->visitado = true;
        FILA[tamFila] = FILA[iniFila]->vizinhos[i];
        tamFila++;
      }
    }
    iniFila++; // Advance the queue front, as if removing the first item (FIFO)
  }
  return -1;
}

int main() {

  // Graph represented by separate vertex variables
  VERTICE A = criaVertice('A');
  VERTICE B = criaVertice('B');
  VERTICE C = criaVertice('C');
  VERTICE D = criaVertice('D');
  VERTICE E = criaVertice('E');
  VERTICE F = criaVertice('F');

  // Connect all vertices as shown in the graph above
  ligaVertices(A, B);
  ligaVertices(A, C);
  ligaVertices(B, D);
  ligaVertices(C, D);
  ligaVertices(B, E);
  ligaVertices(D, E);
  ligaVertices(E, F);
  ligaVertices(D, F);

  // Perform depth-first search
  int res = buscaEmProfundidade(A, F, 0);
  if (res != -1)
    printf("DFS - Encontrou. Distancia: %d.\n", res);
  else
    printf("DFS - Não encontrou.\n");

  // Reset the visited flag on every vertex
  A->visitado = false;
  B->visitado = false;
  C->visitado = false;
  D->visitado = false;
  E->visitado = false;
  F->visitado = false;

  // Perform breadth-first search
  res = buscaEmLargura(A, F);
  if (res != -1)
    printf("BFS - Encontrou. Distancia: %d.\n", res);
  else
    printf("BFS - Não encontrou.\n");

  // Graph represented by an array of vertices
  VERTICE GRAFO[MAX_VERTICES];
  GRAFO[0] = criaVertice('A');
  GRAFO[1] = criaVertice('B');
  GRAFO[2] = criaVertice('C');
  GRAFO[3] = criaVertice('D');
  GRAFO[4] = criaVertice('E');
  GRAFO[5] = criaVertice('F');

  // Connect all vertices as shown in the graph above
  ligaVertices(GRAFO[0], GRAFO[1]);
  ligaVertices(GRAFO[0], GRAFO[2]);
  ligaVertices(GRAFO[1], GRAFO[3]);
  ligaVertices(GRAFO[2], GRAFO[3]);
  ligaVertices(GRAFO[1], GRAFO[4]);
  ligaVertices(GRAFO[3], GRAFO[4]);
  ligaVertices(GRAFO[4], GRAFO[5]);
  ligaVertices(GRAFO[3], GRAFO[5]);

  // Perform depth-first search
  res = buscaEmProfundidade(GRAFO[0], GRAFO[5], 0);
  if (res != -1)
    printf("DFS - Encontrou. Distancia: %d.\n", res);
  else
    printf("DFS - Não encontrou.\n");

  // Reset the visited flag on every vertex
  for (int i = 0; i < MAX_VERTICES; i++) {
    GRAFO[i]->visitado = false;
  }

  // Perform breadth-first search
  res = buscaEmLargura(GRAFO[0], GRAFO[5]);
  if (res != -1)
    printf("BFS - Encontrou. Distancia: %d.\n", res);
  else
    printf("BFS - Não encontrou.\n");

  return 0;
}