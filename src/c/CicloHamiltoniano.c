/*
*
*	Graphs - HAMILTONIAN CYCLE in C
*	Kelvin Salton do Prado - 2015
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

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 6 // MAXIMUM NUMBER OF VERTICES IN THE GRAPH; IF YOU CHANGE THE GRAPH, YOU NEED TO CHANGE THIS VARIABLE AS WELL
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES-1)) // CALCULATES THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// Structure that defines each Vertex in the Graph
typedef struct NODE{
	char id;
	int numNeighbors;
	struct NODE* neighbors[MAX_EDGES];
	bool visited;
}*VERTEX;

VERTEX solution[MAX_VERTICES]; // Array that will store the Hamiltonian cycle solution

// Create a Vertex and return it
VERTEX createVertex(char id){
	VERTEX newVertex = (VERTEX) malloc( sizeof(NODE) ); // Allocate a new Vertex
	newVertex->id = id;
	newVertex->numNeighbors = 0;
	newVertex->visited = false;
	for (int i = 0; i < MAX_EDGES; i++){
		newVertex->neighbors[i] = NULL;
	}
	return newVertex;
}

// Connect the vertices passed as parameters
bool connectVertices(VERTEX v1, VERTEX v2){
	int index = 0;
	while(v1->neighbors[index] != NULL){ // Find the first 'empty' position among neighbors
		index++;
	}
	v1->neighbors[index] = v2; // Add the new neighbor to the list of neighbors
	index = 0;
	while(v2->neighbors[index] != NULL){ // Find the first 'empty' position among neighbors
		index++;
	}
	v2->neighbors[index] = v1; // Add the new neighbor to the list of neighbors
	v1->numNeighbors++; // Increment the number of neighbors
	v2->numNeighbors++; // Increment the number of neighbors
}

bool hamiltonianCycleAuxiliary(int aux){
	
	if( aux == MAX_VERTICES ){
		for (int i = 0; i < solution[aux-1]->numNeighbors; i++){
			if( solution[aux-1]->neighbors[i] == solution[0] ){
				return true;
			}
		}
		return false;
	}

	VERTEX s = solution[aux-1]; // Helper to simplify the code

	for (int i = 0; i < s->numNeighbors; i++){ // Iterate through all neighbors of the vertex at position aux-1 in the solution array
		if( s->neighbors[i]->visited == false ){
			s->neighbors[i]->visited = true;
			solution[aux] = s->neighbors[i];
			if( hamiltonianCycleAuxiliary(aux+1) == true ){
				return true;
			}
			s->neighbors[i]->visited = false;
		}
	}

	return false;
}

bool hamiltonianCycle(VERTEX graph[MAX_VERTICES]){
	graph[0]->visited = true; // Mark the initial position as visited
	solution[0] = graph[0]; // Array that will store the Hamiltonian cycle solution
	return hamiltonianCycleAuxiliary(1);
}

int main(){

    // Graph composed of vertices in an array
	VERTEX GRAPH[MAX_VERTICES];
	GRAPH[0] = createVertex('A');
	GRAPH[1] = createVertex('B');
	GRAPH[2] = createVertex('C');
	GRAPH[3] = createVertex('D');
	GRAPH[4] = createVertex('E');
	GRAPH[5] = createVertex('F');

	// Connect all vertices according to the graph shown in the introduction
	connectVertices(GRAPH[0], GRAPH[1]); // A - B
	connectVertices(GRAPH[0], GRAPH[2]); // A - C
	connectVertices(GRAPH[1], GRAPH[3]); // B - D
	connectVertices(GRAPH[2], GRAPH[3]); // D - C
	connectVertices(GRAPH[1], GRAPH[4]); // B - E
	connectVertices(GRAPH[3], GRAPH[4]); // D - E
	connectVertices(GRAPH[4], GRAPH[5]); // E - F
	connectVertices(GRAPH[3], GRAPH[5]); // D - F
	connectVertices(GRAPH[1], GRAPH[5]); // B - F

	for (int i = 0; i < MAX_VERTICES; i++){
		solution[i] = createVertex('0');
	}

	if( hamiltonianCycle(GRAPH) ){
		printf("Hamiltonian Cycle:\n");
		for (int i = 0; i < MAX_VERTICES; i++){
			printf("%c, ",solution[i]->id);
		}
		printf("\n\n");
	}else{
		printf("No Hamiltonian Cycle\n");
	}

	return 0;
}
