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

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 20 // Constante que define o máximo de vertices que o grafo pode ter

int nroVertices = 0; // Guarda o número de vértices atual
int matriz[MAX_VERTICES][MAX_VERTICES]; // Matriz de Distancia
int componentes;

typedef struct NO{
	char id;
	int nroVizinhos;
	struct AUX* vizinhos[];
	bool visitado;
	int indice; // Guarda a ordem em que o vértice foi criado
}*VERTICE;

typedef struct AUX{
	VERTICE vizinho;
	int valor;
}*ARESTA;

VERTICE criaVertice(char id){
	matriz[nroVertices][nroVertices] = 0;
	VERTICE novo = (VERTICE) malloc( sizeof(NO) );
	novo->id = id;
	novo->nroVizinhos = 0;
	novo->visitado = false;
	novo->indice = nroVertices;
	nroVertices++;
	return novo;
}

void ligaVertice(VERTICE v1, VERTICE v2, int valor){
	matriz[v1->indice][v2->indice] = valor;
	ARESTA nova = (ARESTA) malloc( sizeof(AUX) );
	nova->vizinho = v2;
	nova->valor = valor;
	v1->vizinhos[v1->nroVizinhos] = nova;
	v1->nroVizinhos++;
}

void mostraMatrizDistancia(){
	printf("\nMatriz de Distancia\n");
	for(int l = 0; l < nroVertices; l++){
		for(int c = 0; c < nroVertices; c++){
			if( matriz[l][c] == -1 )
				printf("%d, ", matriz[l][c]);
			else
				printf(" %d, ", matriz[l][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void zeraVariaveis(){
	for(int l = 0; l < MAX_VERTICES; l++){
		for(int c = 0; c < MAX_VERTICES; c++){
			matriz[l][c] = -1;
		}
	}
}

void visitaVizinhos(bool visitados[], int atual){
	for (int i = 0; i < nroVertices; i++){
		if( visitados[i] == false && matriz[atual][i] > 0 ){
			visitados[i] = true;
			componentes++;
			visitaVizinhos(visitados, i);
		}
	}
}

void calculaComponentesConexos(){
	bool visitados[nroVertices];
	for (int i = 0; i < nroVertices; ++i){
		visitados[i] = false;
	}
	for (int i = 0; i < nroVertices; i++){
		if( visitados[i] == false ){
			visitaVizinhos(visitados, i);
		}
	}
}

int main(){
	zeraVariaveis();

	// Matriz de Distância funciona conforme a ordem inserida
	VERTICE A = criaVertice('A');
	VERTICE B = criaVertice('B');
	VERTICE C = criaVertice('C');
	VERTICE D = criaVertice('D');
	VERTICE E = criaVertice('E');

	ligaVertice(A, B, 5);
	ligaVertice(A, C, 6);
	ligaVertice(B, D, 8);
	ligaVertice(C, D, 4);
	ligaVertice(D, B, 2);
	
	calculaComponentesConexos();
	printf("\nComponentes Conexos: %d\n", componentes) ;
	
	mostraMatrizDistancia();

	return 0;
}



//  In English 

/*
*
*
*                     ---------------------
*                     |                   |
*                     |                   |
*            5        V         8         |
*   (A)------------->(B)------------      | 2
*      \                           |      |
*       \                          |      |
*        \ 6                4      V      |
*         ---------->(C)--------->(D)------
*
*
*/


// #define MAX_VERTICES 20 // Constant that defines the maximum number of vertices the graph can have

// int numVertices = 0; // Stores the current number of vertices
// int matrix[MAX_VERTICES][MAX_VERTICES]; // Distance Matrix
// int components; // To count the number of connected components

// typedef struct NODE {
//     char id; // Vertex identifier
//     int numNeighbors; // Number of neighbors
//     struct AUX* neighbors[]; // Array of neighboring vertices
//     bool visited; // Flag to indicate if the vertex has been visited
//     int index; // Stores the order in which the vertex was created
// } *VERTEX;

// typedef struct AUX {
//     VERTEX neighbor; // Pointer to a neighboring vertex
//     int value; // Weight of the edge
// } *EDGE;

// // Function to create a new vertex
// VERTEX createVertex(char id) {
//     matrix[numVertices][numVertices] = 0; // Initialize the distance to itself as 0
//     VERTEX newVertex = (VERTEX) malloc(sizeof(NODE)); // Allocate memory for the new vertex
//     newVertex->id = id; // Set the vertex identifier
//     newVertex->numNeighbors = 0; // Initialize the number of neighbors to 0
//     newVertex->visited = false; // Set the visited flag to false
//     newVertex->index = numVertices; // Store the order of creation
//     numVertices++; // Increment the number of vertices
//     return newVertex; // Return the new vertex
// }

// // Function to connect two vertices with an edge of given value
// void connectVertex(VERTEX v1, VERTEX v2, int value) {
//     matrix[v1->index][v2->index] = value; // Set the distance in the matrix
//     EDGE newEdge = (EDGE) malloc(sizeof(AUX)); // Allocate memory for the new edge
//     newEdge->neighbor = v2; // Set the neighboring vertex
//     newEdge->value = value; // Set the weight of the edge
//     v1->neighbors[v1->numNeighbors] = newEdge; // Add the new edge to the list of neighbors
//     v1->numNeighbors++; // Increment the number of neighbors
// }

// // Function to display the distance matrix
// void displayDistanceMatrix() {
//     printf("\nDistance Matrix\n");
//     for (int l = 0; l < numVertices; l++) {
//         for (int c = 0; c < numVertices; c++) {
//             if (matrix[l][c] == -1) 
//                 printf("%d, ", matrix[l][c]); // Print -1 for unreachable vertices
//             else 
//                 printf(" %d, ", matrix[l][c]); // Print the distance
//         }
//         printf("\n"); // New line for the next row
//     }
//     printf("\n");
// }

// // Function to reset the variables
// void resetVariables() {
//     for (int l = 0; l < MAX_VERTICES; l++) {
//         for (int c = 0; c < MAX_VERTICES; c++) {
//             matrix[l][c] = -1; // Set all distances to -1 (unreachable)
//         }
//     }
// }

// // Recursive function to visit neighbors
// void visitNeighbors(bool visited[], int current) {
//     for (int i = 0; i < numVertices; i++) {
//         if (visited[i] == false && matrix[current][i] > 0) { // Check for unvisited neighbors
//             visited[i] = true; // Mark as visited
//             components++; // Increment the component count
//             visitNeighbors(visited, i); // Recursively visit neighbors
//         }
//     }
// }

// // Function to calculate connected components
// void calculateConnectedComponents() {
//     bool visited[numVertices]; // Array to track visited vertices
//     for (int i = 0; i < numVertices; ++i) {
//         visited[i] = false; // Initialize all vertices as unvisited
//     }
//     for (int i = 0; i < numVertices; i++) {
//         if (visited[i] == false) { // If the vertex is unvisited
//             visited[i] = true; // Mark as visited
//             components++; // Increment the component count
//             visitNeighbors(visited, i); // Visit its neighbors
//         }
//     }
// }

// int main() {
//     resetVariables(); // Reset the variables

//     // The distance matrix works according to the order of insertion
//     VERTEX A = createVertex('A');
//     VERTEX B = createVertex('B');
//     VERTEX C = createVertex('C');
//     VERTEX D = createVertex('D');
//     VERTEX E = createVertex('E');

//     // Connect the vertices with edges and weights
//     connectVertex(A, B, 5);
//     connectVertex(A, C, 6);
//     connectVertex(B, D, 8);
//     connectVertex(C, D, 4);
//     connectVertex(D, B, 2);
    
//     calculateConnectedComponents(); // Calculate the connected components
//     printf("\nConnected Components: %d\n", components); // Print the number of connected components
    
//     displayDistanceMatrix(); // Show the distance matrix

//     return 0;
// }
