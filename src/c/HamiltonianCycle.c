/*
*
*	Grafos - CICLO HAMILTONIANO em C
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
*	6 Vértices
*	9 Arestas
*/

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 6 // MÁXIMO DE VÉRTICES DO GRAFO, SE FOR ALTERAR O GRAFO PRECISA ALTERAR ESTA VARIÁVEL TAMBÉM
#define MAX_ARESTAS (MAX_VERTICES * (MAX_VERTICES-1)) // CALCULA O NÚMERO MÁXIMO DE ARESTAS QUE O GRAFO PODERÁ TER

// Estrutura que define cada Vértice do Grafo
typedef struct NO{
	char id;
	int nroVizinhos;
	struct NO* vizinhos[MAX_ARESTAS];
	bool visitado;
}*VERTICE;

VERTICE solucao[MAX_VERTICES]; // Array que irá guardar a solução do ciclo hamiltoniano

// Cria Vértice e retorna
VERTICE criaVertice(char id){
	VERTICE novoVertice = (VERTICE) malloc( sizeof(NO) ); // Aloca um novo Vértice
	novoVertice->id = id;
	novoVertice->nroVizinhos = 0;
	novoVertice->visitado = false;
	for (int i = 0; i < MAX_ARESTAS; i++){
		novoVertice->vizinhos[i] = NULL;
	}
	return novoVertice;
}

// Liga os vértices passados como parâmetro
bool ligaVertices(VERTICE v1, VERTICE v2){
	int aux = 0;
	while(v1->vizinhos[aux] != NULL){ // Busca a primeira posição 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v1->vizinhos[aux] = v2; // Adiciona o novo vizinho a lista de vizinhos
	aux = 0;
	while(v2->vizinhos[aux] != NULL){ // Busca a primeira posição 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v2->vizinhos[aux] = v1; // Adiciona o novo vizinho a lista de vizinhos
	v1->nroVizinhos++; // Incrementa o número de vizinhos
	v2->nroVizinhos++; // Incrementa o número de vizinhos
}

bool cicloHamiltonianoAuxiliar(int aux){
	
	if( aux == MAX_VERTICES ){
		for (int i = 0; i < solucao[aux-1]->nroVizinhos; i++){
			if( solucao[aux-1]->vizinhos[i] == solucao[0] ){
				return true;
			}
		}
		return false;
	}

	VERTICE s = solucao[aux-1]; // Auxiliar para simplificar o código

	for (int i = 0; i < s->nroVizinhos; i++){ // Percorre todos os vizinhos do vértice de posição aux-1 no array solução
		if( s->vizinhos[i]->visitado == false ){
			s->vizinhos[i]->visitado = true;
			solucao[aux] = s->vizinhos[i];
			if( cicloHamiltonianoAuxiliar(aux+1) == true ){
				return true;
			}
			s->vizinhos[i]->visitado = false;
		}
	}

	return false;
}

bool cicloHamiltoniano(VERTICE grafo[MAX_VERTICES]){
	grafo[0]->visitado = true; // Marca a posição inicial como visitada
	solucao[0] = grafo[0]; // Array que irá guardar a solução do ciclo
	return cicloHamiltonianoAuxiliar(1);
}

int main(){

    // Grafo conjunto de vértices em um array
	VERTICE GRAFO[MAX_VERTICES];
	GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');
	GRAFO[5] = criaVertice('F');

	// Liga todos os vértices de acordo com o GRAFO apresentado na introdução
	ligaVertices(GRAFO[0], GRAFO[1]); // A - B
	ligaVertices(GRAFO[0], GRAFO[2]); // A - C
	ligaVertices(GRAFO[1], GRAFO[3]); // B - D
	ligaVertices(GRAFO[2], GRAFO[3]); // D - C
	ligaVertices(GRAFO[1], GRAFO[4]); // B - E
	ligaVertices(GRAFO[3], GRAFO[4]); // D - E
	ligaVertices(GRAFO[4], GRAFO[5]); // E - F
	ligaVertices(GRAFO[3], GRAFO[5]); // D - F
	ligaVertices(GRAFO[1], GRAFO[5]); // B - F

	for (int i = 0; i < MAX_VERTICES; i++){
		solucao[i] = criaVertice('0');
	}

	if( cicloHamiltoniano(GRAFO) ){
		printf("Ciclo Hamiltoniano:\n");
		for (int i = 0; i < MAX_VERTICES; i++){
			printf("%c, ",solucao[i]->id);
		}
		printf("\n\n");
	}else{
		printf("Nao possui Ciclo Hamiltoniano\n");
	}

	return 0;
}




// English 
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

// #define MAX_VERTICES 6 // MAXIMUM NUMBER OF VERTICES IN THE GRAPH; IF THE GRAPH CHANGES, THIS VARIABLE MUST BE UPDATED
// #define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1)) // CALCULATES THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// // Structure that defines each Vertex of the Graph
// typedef struct NODE {
//     char id;
//     int numNeighbors;
//     struct NODE* neighbors[MAX_EDGES];
//     bool visited;
// }*VERTEX;

// VERTEX solution[MAX_VERTICES]; // Array to hold the solution of the Hamiltonian cycle

// // Create a Vertex and return it
// VERTEX createVertex(char id) {
//     VERTEX newVertex = (VERTEX)malloc(sizeof(struct NODE)); // Allocate a new Vertex
//     if (newVertex == NULL) {
//         fprintf(stderr, "Failed to allocate memory for the vertex.\n");
//         exit(EXIT_FAILURE);
//     }
//     newVertex->id = id;
//     newVertex->numNeighbors = 0;
//     newVertex->visited = false;
//     for (int i = 0; i < MAX_EDGES; i++) {
//         newVertex->neighbors[i] = NULL;
//     }
//     return newVertex;
// }

// // Connect the vertices passed as parameters
// bool connectVertices(VERTEX v1, VERTEX v2) {
//     int aux = 0;
//     while (v1->neighbors[aux] != NULL && aux < MAX_EDGES) { // Find the first empty position (NULL) in the neighbors
//         aux++;
//     }
//     if (aux < MAX_EDGES) {
//         v1->neighbors[aux] = v2; // Add the new neighbor to the list of neighbors
//         aux = 0;
//         while (v2->neighbors[aux] != NULL && aux < MAX_EDGES) { // Find the first empty position (NULL) in the neighbors
//             aux++;
//         }
//         if (aux < MAX_EDGES) {
//             v2->neighbors[aux] = v1; // Add the new neighbor to the list of neighbors
//             v1->numNeighbors++; // Increment the number of neighbors
//             v2->numNeighbors++; // Increment the number of neighbors
//             return true;
//         }
//     }
//     return false;
// }

// bool hamiltonianCycleHelper(int aux) {
//     if (aux == MAX_VERTICES) {
//         for (int i = 0; i < solution[aux - 1]->numNeighbors; i++) {
//             if (solution[aux - 1]->neighbors[i] == solution[0]) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     VERTEX s = solution[aux - 1]; // Helper for simplifying the code

//     for (int i = 0; i < s->numNeighbors; i++) { // Traverse all neighbors of the vertex at position aux-1 in the solution array
//         if (s->neighbors[i]->visited == false) {
//             s->neighbors[i]->visited = true;
//             solution[aux] = s->neighbors[i];
//             if (hamiltonianCycleHelper(aux + 1) == true) {
//                 return true;
//             }
//             s->neighbors[i]->visited = false;
//         }
//     }

//     return false;
// }

// bool hamiltonianCycle(VERTEX graph[MAX_VERTICES]) {
//     graph[0]->visited = true; // Mark the starting position as visited
//     solution[0] = graph[0]; // Array that will hold the solution of the cycle
//     return hamiltonianCycleHelper(1);
// }

// void freeMemory(VERTEX graph[MAX_VERTICES]) {
//     for (int i = 0; i < MAX_VERTICES; i++) {
//         free(graph[i]);
//     }
// }

// int main() {
//     // Graph set of vertices in an array
//     VERTEX GRAPH[MAX_VERTICES];
//     for (char id = 'A'; id < 'A' + MAX_VERTICES; id++) {
//         GRAPH[id - 'A'] = createVertex(id);
//     }

//     // Connect all vertices according to the GRAPH presented in the introduction
//     connectVertices(GRAPH[0], GRAPH[1]); // A - B
//     connectVertices(GRAPH[0], GRAPH[2]); // A - C
//     connectVertices(GRAPH[1], GRAPH[3]); // B - D
//     connectVertices(GRAPH[2], GRAPH[3]); // C - D
//     connectVertices(GRAPH[1], GRAPH[4]); // B - E
//     connectVertices(GRAPH[3], GRAPH[4]); // D - E
//     connectVertices(GRAPH[4], GRAPH[5]); // E - F
//     connectVertices(GRAPH[3], GRAPH[5]); // D - F
//     connectVertices(GRAPH[1], GRAPH[5]); // B - F

//     for (int i = 0; i < MAX_VERTICES; i++) {
//         solution[i] = createVertex('0');
//     }

//     if (hamiltonianCycle(GRAPH)) {
//         printf("Hamiltonian Cycle:\n");
//         for (int i = 0; i < MAX_VERTICES; i++) {
//             printf("%c", solution[i]->id);
//             if (i < MAX_VERTICES - 1) {
//                 printf(" -> ");
//             }
//         }
//         printf(".\n\n");
//     } else {
//         printf("No Hamiltonian Cycle\n");
//     }

//     freeMemory(GRAPH); // Free the allocated memory

//     return 0;
// }
