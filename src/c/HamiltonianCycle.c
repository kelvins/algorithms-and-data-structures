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
#define MAX_EDGES                                                              \
  (MAX_VERTICES *                                                              \
   (MAX_VERTICES -                                                             \
    1)) // CALCULATE THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// Structure defining each graph vertex
typedef struct Node {
  char id;
  int neighborCount;
  struct Node *neighbors[MAX_EDGES];
  bool visited;
} *Vertex;

Vertex solution[MAX_VERTICES]; // Array that stores the Hamiltonian cycle

// Create and return a vertex
Vertex createVertex(char id) {
  Vertex newVertex = (Vertex)malloc(sizeof(Node)); // Allocate a new vertex
  newVertex->id = id;
  newVertex->neighborCount = 0;
  newVertex->visited = false;
  for (int i = 0; i < MAX_EDGES; i++) {
    newVertex->neighbors[i] = NULL;
  }
  return newVertex;
}

// Connect the vertices passed as parameters
bool connectVertices(Vertex v1, Vertex v2) {
  int temporary = 0;
  while (v1->neighbors[temporary] !=
         NULL) { // Find the first empty (NULL) neighbor slot
    temporary++;
  }
  v1->neighbors[temporary] = v2; // Add the new neighbor to the neighbor list
  temporary = 0;
  while (v2->neighbors[temporary] !=
         NULL) { // Find the first empty (NULL) neighbor slot
    temporary++;
  }
  v2->neighbors[temporary] = v1; // Add the new neighbor to the neighbor list
  v1->neighborCount++;           // Increment the number of neighbors
  v2->neighborCount++;           // Increment the number of neighbors
}

bool hamiltonianCycleHelper(int temporary) {

  if (temporary == MAX_VERTICES) {
    for (int i = 0; i < solution[temporary - 1]->neighborCount; i++) {
      if (solution[temporary - 1]->neighbors[i] == solution[0]) {
        return true;
      }
    }
    return false;
  }

  Vertex s = solution[temporary - 1]; // Helper variable to simplify the code

  for (int i = 0; i < s->neighborCount;
       i++) { // Visit all neighbors of the vertex at position aux-1 in the
              // array
    if (s->neighbors[i]->visited == false) {
      s->neighbors[i]->visited = true;
      solution[temporary] = s->neighbors[i];
      if (hamiltonianCycleHelper(temporary + 1) == true) {
        return true;
      }
      s->neighbors[i]->visited = false;
    }
  }

  return false;
}

bool hamiltonianCycle(Vertex graph[MAX_VERTICES]) {
  graph[0]->visited = true; // Mark the starting vertex as visited
  solution[0] = graph[0];   // Store the first vertex in the cycle
  return hamiltonianCycleHelper(1);
}

int main() {

  // Graph represented by an array of vertices
  Vertex GRAPH[MAX_VERTICES];
  GRAPH[0] = createVertex('A');
  GRAPH[1] = createVertex('B');
  GRAPH[2] = createVertex('C');
  GRAPH[3] = createVertex('D');
  GRAPH[4] = createVertex('E');
  GRAPH[5] = createVertex('F');

  // Connect all vertices as shown in the graph above
  connectVertices(GRAPH[0], GRAPH[1]); // A - B
  connectVertices(GRAPH[0], GRAPH[2]); // A - C
  connectVertices(GRAPH[1], GRAPH[3]); // B - D
  connectVertices(GRAPH[2], GRAPH[3]); // D - C
  connectVertices(GRAPH[1], GRAPH[4]); // B - E
  connectVertices(GRAPH[3], GRAPH[4]); // D - E
  connectVertices(GRAPH[4], GRAPH[5]); // E - F
  connectVertices(GRAPH[3], GRAPH[5]); // D - F
  connectVertices(GRAPH[1], GRAPH[5]); // B - F

  for (int i = 0; i < MAX_VERTICES; i++) {
    solution[i] = createVertex('0');
  }

  if (hamiltonianCycle(GRAPH)) {
    printf("Hamiltonian cycle:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
      printf("%c, ", solution[i]->id);
    }
    printf("\n\n");
  } else {
    printf("No Hamiltonian cycle exists\n");
  }

  return 0;
}