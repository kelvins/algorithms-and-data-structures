/*
 *
 *
 *                     ---------------------
 *                     |                   |
 *                     |                   |
 *            5        V         8         |
 *	(A)------------->(B)------------      | 2
 *      \                           |      |
 *       \                          |      |
 *        \ 6                4      V      |
 *         ---------->(C)--------->(D)------
 *
 *
 */

#include <malloc.h>
#include <stdio.h>

#define MAX_VERTICES 20 // Maximum number of vertices the graph can have

int vertexCount = 0;                    // Current number of vertices
int matrix[MAX_VERTICES][MAX_VERTICES]; // Distance matrix
int components;

typedef struct Node {
  char id;
  int neighborCount;
  struct EdgeNode *neighbors[];
  bool visited;
  int index; // Stores the order in which the vertex was created
} *Vertex;

typedef struct EdgeNode {
  Vertex vizinho;
  int value;
} *Edge;

Vertex createVertex(char id) {
  matrix[vertexCount][vertexCount] = 0;
  Vertex newNode = (Vertex)malloc(sizeof(Node));
  newNode->id = id;
  newNode->neighborCount = 0;
  newNode->visited = false;
  newNode->index = vertexCount;
  vertexCount++;
  return newNode;
}

void connectVertices(Vertex v1, Vertex v2, int value) {
  matrix[v1->index][v2->index] = value;
  Edge newNode = (Edge)malloc(sizeof(EdgeNode));
  newNode->vizinho = v2;
  newNode->value = value;
  v1->neighbors[v1->neighborCount] = newNode;
  v1->neighborCount++;
}

void printDistanceMatrix() {
  printf("\nDistance matrix\n");
  for (int l = 0; l < vertexCount; l++) {
    for (int c = 0; c < vertexCount; c++) {
      if (matrix[l][c] == -1)
        printf("%d, ", matrix[l][c]);
      else
        printf(" %d, ", matrix[l][c]);
    }
    printf("\n");
  }
  printf("\n");
}

void zeraVariaveis() {
  for (int l = 0; l < MAX_VERTICES; l++) {
    for (int c = 0; c < MAX_VERTICES; c++) {
      matrix[l][c] = -1;
    }
  }
}

void visitNeighbors(bool visited[], int current) {
  for (int i = 0; i < vertexCount; i++) {
    if (visited[i] == false && matrix[current][i] > 0) {
      visited[i] = true;
      components++;
      visitNeighbors(visited, i);
    }
  }
}

void findConnectedComponents() {
  bool visited[vertexCount];
  for (int i = 0; i < vertexCount; ++i) {
    visited[i] = false;
  }
  for (int i = 0; i < vertexCount; i++) {
    if (visited[i] == false) {
      visitNeighbors(visited, i);
    }
  }
}

int main() {
  zeraVariaveis();

  // The distance matrix follows the insertion order
  Vertex A = createVertex('A');
  Vertex B = createVertex('B');
  Vertex C = createVertex('C');
  Vertex D = createVertex('D');
  Vertex E = createVertex('E');

  connectVertices(A, B, 5);
  connectVertices(A, C, 6);
  connectVertices(B, D, 8);
  connectVertices(C, D, 4);
  connectVertices(D, B, 2);

  findConnectedComponents();
  printf("\nConnected components: %d\n", components);

  printDistanceMatrix();

  return 0;
}