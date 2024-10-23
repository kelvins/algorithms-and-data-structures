#include <iostream>
#include <queue>
#include <vector>

#define MAX_VERTICES 6 // Maximum number of vertices in the graph

// Structure that defines each Vertex of the Graph
struct Vertex {
  char id;
  std::vector<Vertex *> neighbors; // List of neighbors
  bool visited;

  Vertex(char id) : id(id), visited(false) {}
};

// Creates a vertex and returns it
Vertex *createVertex(char id) { return new Vertex(id); }

// Links two vertices (makes them neighbors)
void linkVertices(Vertex *v1, Vertex *v2) {
  v1->neighbors.push_back(v2); // Add v2 as a neighbor of v1
  v2->neighbors.push_back(v1); // Add v1 as a neighbor of v2
}

/*
 * Depth First Search (DFS)
 * Recursively visits neighbors of the starting vertex
 */
int depthFirstSearch(Vertex *start, Vertex *destination, int steps) {
  start->visited = true; // Mark the current vertex as visited
  if (start == destination)
    return steps; // If found, return the distance

  for (Vertex *neighbor : start->neighbors) { // Visit all neighbors
    if (!neighbor->visited) {                 // If neighbor hasn't been visited
      int result = depthFirstSearch(neighbor, destination, steps + 1);
      if (result != -1)
        return result; // If destination found, return result
    }
  }
  return -1; // Destination not found
}

/*
 * Breadth First Search (BFS)
 * Uses a queue to traverse level by level
 */
int breadthFirstSearch(Vertex *start, Vertex *destination) {
  std::queue<Vertex *> q;
  q.push(start); // Enqueue starting vertex
  start->visited = true;

  int steps = 0;

  while (!q.empty()) {
    int qSize = q.size(); // Current queue size (level size)

    // Process all vertices at the current level
    for (int i = 0; i < qSize; i++) {
      Vertex *current = q.front();
      q.pop();

      if (current == destination)
        return steps; // If destination found, return steps

      // Enqueue all unvisited neighbors
      for (Vertex *neighbor : current->neighbors) {
        if (!neighbor->visited) {
          neighbor->visited = true;
          q.push(neighbor);
        }
      }
    }
    steps++; // Increment the level
  }
  return -1; // Destination not found
}

int main() {
  // Create vertices
  Vertex *A = createVertex('A');
  Vertex *B = createVertex('B');
  Vertex *C = createVertex('C');
  Vertex *D = createVertex('D');
  Vertex *E = createVertex('E');
  Vertex *F = createVertex('F');

  // Link vertices as per the graph structure
  linkVertices(A, B);
  linkVertices(A, C);
  linkVertices(B, D);
  linkVertices(C, D);
  linkVertices(B, E);
  linkVertices(D, E);
  linkVertices(E, F);
  linkVertices(D, F);

  // Perform Depth First Search
  int result = depthFirstSearch(A, F, 0);
  if (result != -1)
    std::cout << "DFS - Found. Distance: " << result << std::endl;
  else
    std::cout << "DFS - Not Found." << std::endl;

  // Reset visited status for all vertices
  A->visited = false;
  B->visited = false;
  C->visited = false;
  D->visited = false;
  E->visited = false;
  F->visited = false;

  // Perform Breadth First Search
  result = breadthFirstSearch(A, F);
  if (result != -1)
    std::cout << "BFS - Found. Distance: " << result << std::endl;
  else
    std::cout << "BFS - Not Found." << std::endl;

  return 0;
}
