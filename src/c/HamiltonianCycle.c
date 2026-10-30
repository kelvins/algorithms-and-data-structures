/*
 *
 *	Graphs - HAMILTONIAN CYCLE in C
 *
 *                      -----------------------------------
 *                      |                                 |
 *   (A)---------------(B)-------------(E)---------------(F)
 *    |                 |               |                 |
 *    |                 |               |                 |
 *    |                 |               |                 |
 *   (C)---------------(D)---------------                 |
 *                      |                                 |
 *                      -----------------------------------
 *
 *	6 Vertices
 *	9 Edges
 */

#include <malloc.h>
#include <stdio.h>

#define MAX_VERTICES                                                           \
  6 // MAXIMUM NUMBER OF GRAPH VERTICES; update this value if the graph changes
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

VERTICE solucao[MAX_VERTICES]; // Array that stores the Hamiltonian cycle

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

bool cicloHamiltonianoAuxiliar(int aux) {

  if (aux == MAX_VERTICES) {
    for (int i = 0; i < solucao[aux - 1]->nroVizinhos; i++) {
      if (solucao[aux - 1]->vizinhos[i] == solucao[0]) {
        return true;
      }
    }
    return false;
  }

  VERTICE s = solucao[aux - 1]; // Helper variable to simplify the code

  for (int i = 0; i < s->nroVizinhos;
       i++) { // Visit all neighbors of the vertex at position aux-1 in the
              // array
    if (s->vizinhos[i]->visitado == false) {
      s->vizinhos[i]->visitado = true;
      solucao[aux] = s->vizinhos[i];
      if (cicloHamiltonianoAuxiliar(aux + 1) == true) {
        return true;
      }
      s->vizinhos[i]->visitado = false;
    }
  }

  return false;
}

bool cicloHamiltoniano(VERTICE grafo[MAX_VERTICES]) {
  grafo[0]->visitado = true; // Mark the starting vertex as visited
  solucao[0] = grafo[0];     // Store the first vertex in the cycle
  return cicloHamiltonianoAuxiliar(1);
}

int main() {

  // Graph represented by an array of vertices
  VERTICE GRAFO[MAX_VERTICES];
  GRAFO[0] = criaVertice('A');
  GRAFO[1] = criaVertice('B');
  GRAFO[2] = criaVertice('C');
  GRAFO[3] = criaVertice('D');
  GRAFO[4] = criaVertice('E');
  GRAFO[5] = criaVertice('F');

  // Connect all vertices as shown in the graph above
  ligaVertices(GRAFO[0], GRAFO[1]); // A - B
  ligaVertices(GRAFO[0], GRAFO[2]); // A - C
  ligaVertices(GRAFO[1], GRAFO[3]); // B - D
  ligaVertices(GRAFO[2], GRAFO[3]); // D - C
  ligaVertices(GRAFO[1], GRAFO[4]); // B - E
  ligaVertices(GRAFO[3], GRAFO[4]); // D - E
  ligaVertices(GRAFO[4], GRAFO[5]); // E - F
  ligaVertices(GRAFO[3], GRAFO[5]); // D - F
  ligaVertices(GRAFO[1], GRAFO[5]); // B - F

  for (int i = 0; i < MAX_VERTICES; i++) {
    solucao[i] = criaVertice('0');
  }

  if (cicloHamiltoniano(GRAFO)) {
    printf("Ciclo Hamiltoniano:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
      printf("%c, ", solucao[i]->id);
    }
    printf("\n\n");
  } else {
    printf("Nao possui Ciclo Hamiltoniano\n");
  }

  return 0;
}