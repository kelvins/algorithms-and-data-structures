/*
*
*	Graphs - Implementation of an undirected graph structure in C
*	Search Methods: Depth-First Search and Breadth-First Search
*	Kelvin Salton do Prado - 2015
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

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 6 // MAXIMUM NUMBER OF GRAPH VERTICES; IF YOU CHANGE THE GRAPH, YOU NEED TO CHANGE THIS VARIABLE TOO
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1)) // CALCULATE THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// Structure defining each Vertex of the Graph
typedef struct NODE {
	char id;
	int numNeighbors;
	struct NODE* neighbors[MAX_EDGES];
	bool visited;
} *VERTEX;

// Create a Vertex and return it
VERTEX createVertex(char id) {
	VERTEX newVertex = (VERTEX)malloc(sizeof(NODE)); // Allocate a new Vertex
	newVertex->id = id;
	newVertex->numNeighbors = 0;
	newVertex->visited = false;
	for (int i = 0; i < MAX_EDGES; i++) {
		newVertex->neighbors[i] = NULL;
	}
	return newVertex;
}

// Connect the vertices passed as parameters
bool connectVertices(VERTEX v1, VERTEX v2) {
	int aux = 0;
	while (v1->neighbors[aux] != NULL) { // Find the first 'empty' position (NULL) among neighbors
		aux++;
	}
	v1->neighbors[aux] = v2; // Add the new neighbor to the list of neighbors
	aux = 0;
	while (v2->neighbors[aux] != NULL) { // Find the first 'empty' position (NULL) among neighbors
		aux++;
	}
	v2->neighbors[aux] = v1; // Add the new neighbor to the list of neighbors
	v1->numNeighbors++; // Increment the number of neighbors
	v2->numNeighbors++; // Increment the number of neighbors
}

/*
*	Depth-First Search - DFS
*	Traverse all neighbors connected to the vertex first
*
*/
int depthFirstSearch(VERTEX start, VERTEX destination, int visited) {
	start->visited = true; // Mark the vertex passed as 'start' as visited
	if (start == destination) return visited; // If it's the destination, return the distance traveled

	int aux = 0;
	while (start->neighbors[aux] != NULL) { // While there are neighbors to visit
		if (start->neighbors[aux]->visited == false) { // If the neighbor hasn't been visited yet
			// Call recursively, passing the new neighbor as 'start', which will traverse all its neighbors, and so on
			int response = depthFirstSearch(start->neighbors[aux], destination, visited + 1);
			// If the return is greater than -1, then it has been found, so return the response
			if (response != -1) return response;
		}
		aux++; // Increment 1 in the list of neighbors
	}

	return -1; // Vertex not found
}

/*
*	Breadth-First Search - BFS
*	Implemented using the concept of a queue, but using a simple array
*	This way, it does not remove the 'vertex' from the array, it just moves one position forward
*	Traverse all vertices by level
*/
int breadthFirstSearch(VERTEX start, VERTEX destination) {
	int frontOfQueue = 0; // Variable to control the front position of the queue, used for the WHILE loop
	int queueSize = 1; // Variable to control the size of the queue

	VERTEX QUEUE[MAX_VERTICES]; // Queue that will store the vertices to be compared
	for (int i = 0; i < MAX_VERTICES; i++) { // Since the list is not dynamic, it needs to be 'cleared' first
		QUEUE[i] = NULL;
	}
	QUEUE[frontOfQueue] = start; // Position [0] of the queue receives the starting vertex

	// While the queue is not empty, do
	while (frontOfQueue < queueSize) {
		// If the element about to 'exit' the queue is the sought-after (destination), then return frontOfQueue, which is the distance traveled to find it
		if (QUEUE[frontOfQueue] == destination) return frontOfQueue;

		/*
		*	For all neighbors of the vertex that is about to 'exit' the queue:
		*	Mark them all as visited to prevent them from being added to the queue again,
		*	and then add them to the queue, increasing the queue size
		*/
		for (int i = 0; i < QUEUE[frontOfQueue]->numNeighbors; i++) {
			if (QUEUE[frontOfQueue]->neighbors[i]->visited == false) {
				QUEUE[frontOfQueue]->neighbors[i]->visited = true;
				QUEUE[queueSize] = QUEUE[frontOfQueue]->neighbors[i];
				queueSize++;
			}
		}
		frontOfQueue++; // Increment 1 at the front of the queue, as if the first one that entered the queue had been removed (FIFO - First In First Out)
	}
	return -1;
}

int main() {

	// Graph with a set of independent vertices
	VERTEX A = createVertex('A');
	VERTEX B = createVertex('B');
	VERTEX C = createVertex('C');
	VERTEX D = createVertex('D');
	VERTEX E = createVertex('E');
	VERTEX F = createVertex('F');
	
	// Connect all vertices according to the GRAPH presented in the introduction
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

	// 'Reset' all 'visited' attributes of all vertices to 'false'
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

    // Graph with a set of vertices in an array
	VERTEX GRAPH[MAX_VERTICES];
	GRAPH[0] = createVertex('
