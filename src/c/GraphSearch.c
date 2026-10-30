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

/*
 *	Depth-First Search (DFS)
 *	Visit neighbors in the order they were connected to the vertex.
 *
 */
int depthFirstSearch(Vertex start, Vertex destination, int visited) {
  start->visited = true; // Mark the current vertex as visited
  if (start == destination)
    return visited; // If this is the destination, return the distance

  int temporary = 0;
  while (start->neighbors[temporary] !=
         NULL) { // While there are neighbors to visit
    if (start->neighbors[temporary]->visited ==
        false) { // If the neighbor has not been visited
      // Recurse from the new neighbor, visiting all of its neighbors in turn
      int resposta = depthFirstSearch(start->neighbors[temporary], destination,
                                      visited + 1);
      // If the result is greater than -1, the destination was found; return it
      if (resposta != -1)
        return resposta;
    }
    temporary++; // Advance to the next neighbor
  }

  return -1; // The vertex was not found
}

/*
 *	Breadth-First Search (BFS)
 *	Implemented as a queue using a simple array
 *	Instead of removing a vertex from the array, it advances one position
 *and visits all vertices by level
 */
int breadthFirstSearch(Vertex start, Vertex destination) {
  int queueHead = 0; // Queue position, used to control the while loop
  int queueSize = 1; // Queue size

  Vertex Queue[MAX_VERTICES]; // Queue holding the vertices to compare
  for (int i = 0; i < MAX_VERTICES;
       i++) { // Clear the array first because it is not dynamically allocated
    Queue[i] = NULL;
  }
  Queue[queueHead] = start; // Store the starting vertex at queue position 0

  // Process the queue until it is empty
  while (queueHead < queueSize) {
    // If the next element is the destination, return the distance (iniFila)
    if (Queue[queueHead] == destination)
      return queueHead;

    /*
     *	For each neighbor of the vertex at the front of the queue:
     *	Mark each as visited so it is not added to the queue again,
     *	then enqueue it and increase the queue size
     */
    for (int i = 0; i < Queue[queueHead]->neighborCount; i++) {
      if (Queue[queueHead]->neighbors[i]->visited == false) {
        Queue[queueHead]->neighbors[i]->visited = true;
        Queue[queueSize] = Queue[queueHead]->neighbors[i];
        queueSize++;
      }
    }
    queueHead++; // Advance the queue front, as if removing the first item
                 // (FIFO)
  }
  return -1;
}

int main() {

  // Graph represented by separate vertex variables
  Vertex A = createVertex('A');
  Vertex B = createVertex('B');
  Vertex C = createVertex('C');
  Vertex D = createVertex('D');
  Vertex E = createVertex('E');
  Vertex F = createVertex('F');

  // Connect all vertices as shown in the graph above
  connectVertices(A, B);
  connectVertices(A, C);
  connectVertices(B, D);
  connectVertices(C, D);
  connectVertices(B, E);
  connectVertices(D, E);
  connectVertices(E, F);
  connectVertices(D, F);

  // Perform depth-first search
  int res = depthFirstSearch(A, F, 0);
  if (res != -1)
    printf("DFS - Found. Distance: %d.\n", res);
  else
    printf("DFS - Not found.\n");

  // Reset the visited flag on every vertex
  A->visited = false;
  B->visited = false;
  C->visited = false;
  D->visited = false;
  E->visited = false;
  F->visited = false;

  // Perform breadth-first search
  res = breadthFirstSearch(A, F);
  if (res != -1)
    printf("BFS - Found. Distance: %d.\n", res);
  else
    printf("BFS - Not found.\n");

  // Graph represented by an array of vertices
  Vertex GRAPH[MAX_VERTICES];
  GRAPH[0] = createVertex('A');
  GRAPH[1] = createVertex('B');
  GRAPH[2] = createVertex('C');
  GRAPH[3] = createVertex('D');
  GRAPH[4] = createVertex('E');
  GRAPH[5] = createVertex('F');

  // Connect all vertices as shown in the graph above
  connectVertices(GRAPH[0], GRAPH[1]);
  connectVertices(GRAPH[0], GRAPH[2]);
  connectVertices(GRAPH[1], GRAPH[3]);
  connectVertices(GRAPH[2], GRAPH[3]);
  connectVertices(GRAPH[1], GRAPH[4]);
  connectVertices(GRAPH[3], GRAPH[4]);
  connectVertices(GRAPH[4], GRAPH[5]);
  connectVertices(GRAPH[3], GRAPH[5]);

  // Perform depth-first search
  res = depthFirstSearch(GRAPH[0], GRAPH[5], 0);
  if (res != -1)
    printf("DFS - Found. Distance: %d.\n", res);
  else
    printf("DFS - Not found.\n");

  // Reset the visited flag on every vertex
  for (int i = 0; i < MAX_VERTICES; i++) {
    GRAPH[i]->visited = false;
  }

  // Perform breadth-first search
  res = breadthFirstSearch(GRAPH[0], GRAPH[5]);
  if (res != -1)
    printf("BFS - Found. Distance: %d.\n", res);
  else
    printf("BFS - Not found.\n");

  return 0;
}