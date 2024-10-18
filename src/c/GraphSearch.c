/*
*
*	Grafos - Implementação de uma estrutura de Grafo não dirigido em C
*	Métodos de Busca: Busca em Profundidade e Busca em Largura
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
*	6 Vértices
*	8 Arestas
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

/*
*	Busca em Profundidade - DFS - Depht First Search
*	Percorre primeiro todos os vizinhos que foram ligados primeiro ao vértice
*
*/
int buscaEmProfundidade(VERTICE inicio, VERTICE destino, int visitados){
	inicio->visitado = true; // Marca o Vértice que está passando inicio como já visitado
	if( inicio == destino ) return visitados; // Se for o buscado (destino) retorna ele

	int aux = 0;
	while( inicio->vizinhos[aux] != NULL ){ // Enquanto existe vizinhos a serem visitados
		if( inicio->vizinhos[aux]->visitado == false ){ // Se o vizinho ainda não foi visitado
			// Chama recursivamente passando novo vizinho como iniício, ou seja, irá percorrer todos os vizinhos dele, e assim, sucessivamente
			int resposta = buscaEmProfundidade(inicio->vizinhos[aux], destino, visitados+1);
			// Se o retorno for maior que -1 então é porque encontrou, sendo assim, já retorna a resposta
			if( resposta != -1 ) return resposta;
		}
		aux++; // Incrementa 1 na lista de vizinhos
	}

	return -1; // Não encontrou o vértice
}

/*
*	Busca em Largura - BFS - Breadth First Search
*	Implementada com o conceito de fila, porém utilizando um array simples
*	Assim ela não excluí o 'vértice' do array, apenas pula uma posição para a frente
*	Percorre todos os vértices por nível
*/
int buscaEmLargura(VERTICE inicio, VERTICE destino){
	int iniFila = 0; // Variável que controla a posição do inicio da fila, é utilizada para controlar o WHILE
	int tamFila = 1; // Variável que controla o tamanho da fila

	VERTICE FILA[MAX_VERTICES]; // Fila que irá guardar os vértices a serem comparados
	for (int i = 0; i < MAX_VERTICES; i++){ // Como a lista não é dinâmica, ela precisa ser 'limpa' primeiro
		FILA[i] = NULL;
	}
	FILA[iniFila] = inicio; // Posição [0] da fila recebe o vértice de início

	// Enquanto não terminar a fila faça
	while( iniFila < tamFila ){
		// Se o elemento que está para 'sair' da fila for o buscado (destino) então retorna iniFila, que foi a distância percorrida para encontrar
		if( FILA[iniFila] == destino ) return iniFila;

		/*
		*	Para todos os vizinhos do vértice que está para 'sair' da fila:
		*	Marca todos como visitado, para não coloca-los na fila novamente,
		*	e então os coloca na fila, e aumenta o tamanho da fila
		*/
		for (int i = 0; i < FILA[iniFila]->nroVizinhos; i++){
			if( FILA[iniFila]->vizinhos[i]->visitado == false ){
				FILA[iniFila]->vizinhos[i]->visitado = true;
				FILA[tamFila] = FILA[iniFila]->vizinhos[i];
				tamFila++;
			}
		}
		iniFila++; // Incrementa 1 no inicio da fila, como se tivesse excluído o primeiro que entrou na fila (FIFO - First In First Out)
	}
	return -1;
}

int main(){

	// Grafo conjunto de vértices independentes
	VERTICE A = criaVertice('A');
	VERTICE B = criaVertice('B');
	VERTICE C = criaVertice('C');
	VERTICE D = criaVertice('D');
	VERTICE E = criaVertice('E');
	VERTICE F = criaVertice('F');
	
	// Liga todos os vértices de acordo com o GRAFO apresentado na introdução
	ligaVertices(A, B);
	ligaVertices(A, C);
	ligaVertices(B, D);
	ligaVertices(C, D);
	ligaVertices(B, E);
	ligaVertices(D, E);
	ligaVertices(E, F);
	ligaVertices(D, F);

	// Realiza a busca em profundidade
	int res = buscaEmProfundidade(A, F, 0);
	if( res != -1 )
		printf("DFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("DFS - Não encontrou.\n");

	// 'Zera' todos os atributos 'visitado' de todos os vértices para 'false'
	A->visitado = false;
	B->visitado = false;
	C->visitado = false;
	D->visitado = false;
	E->visitado = false;
	F->visitado = false;

	// Realiza a busca em largura
	res = buscaEmLargura(A, F);
	if( res != -1 )
		printf("BFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("BFS - Não encontrou.\n");

    // Grafo conjunto de vértices em um array
	VERTICE GRAFO[MAX_VERTICES];
	GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');
	GRAFO[5] = criaVertice('F');

	// Liga todos os vértices de acordo com o GRAFO apresentado na introdução
	ligaVertices(GRAFO[0], GRAFO[1]);
	ligaVertices(GRAFO[0], GRAFO[2]);
	ligaVertices(GRAFO[1], GRAFO[3]);
	ligaVertices(GRAFO[2], GRAFO[3]);
	ligaVertices(GRAFO[1], GRAFO[4]);
	ligaVertices(GRAFO[3], GRAFO[4]);
	ligaVertices(GRAFO[4], GRAFO[5]);
	ligaVertices(GRAFO[3], GRAFO[5]);

	// Realiza a busca em profundidade
	res = buscaEmProfundidade(GRAFO[0], GRAFO[5], 0);
	if( res != -1 )
		printf("DFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("DFS - Não encontrou.\n");

	// 'Zera' todos os atributos 'visitado' de todos os vértices para 'false'
	for (int i = 0; i < MAX_VERTICES; i++){
		GRAFO[i]->visitado = false;
	}
	
	// Realiza a busca em largura
	res = buscaEmLargura(GRAFO[0], GRAFO[5]);
	if( res != -1 )
		printf("BFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("BFS - Não encontrou.\n");

	return 0;
}


// In english 

/*
*
* Graphs - Implementation of an undirected graph structure in C
* Search Methods: Depth-First Search (DFS) and Breadth-First Search (BFS)
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

// #define MAX_VERTICES 6 // MAXIMUM NUMBER OF VERTICES IN THE GRAPH; IF THE GRAPH IS CHANGED, THIS VARIABLE MUST ALSO BE CHANGED
// #define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1)) // CALCULATES THE MAXIMUM NUMBER OF EDGES THE GRAPH CAN HAVE

// // Structure defining each vertex of the graph
// typedef struct NODE {
//     char id; // Vertex identifier
//     int numNeighbors; // Number of neighbors
//     struct NODE* neighbors[MAX_EDGES]; // Array of neighbors
//     bool visited; // Flag to indicate if the vertex has been visited
// } *VERTEX;

// // Create vertex and return it
// VERTEX createVertex(char id) {
//     VERTEX newVertex = (VERTEX) malloc(sizeof(NODE)); // Allocate a new vertex
//     newVertex->id = id; // Set the vertex identifier
//     newVertex->numNeighbors = 0; // Initialize the number of neighbors
//     newVertex->visited = false; // Set the visited flag to false
//     for (int i = 0; i < MAX_EDGES; i++) {
//         newVertex->neighbors[i] = NULL; // Initialize the neighbors array
//     }
//     return newVertex; // Return the new vertex
// }

// // Connect the specified vertices
// bool connectVertices(VERTEX v1, VERTEX v2) {
//     int aux = 0;
//     while (v1->neighbors[aux] != NULL) { // Find the first 'empty' (NULL) position among neighbors
//         aux++;
//     }
//     v1->neighbors[aux] = v2; // Add the new neighbor to the list
//     aux = 0;
//     while (v2->neighbors[aux] != NULL) { // Find the first 'empty' (NULL) position among neighbors
//         aux++;
//     }
//     v2->neighbors[aux] = v1; // Add the new neighbor to the list
//     v1->numNeighbors++; // Increment the number of neighbors
//     v2->numNeighbors++; // Increment the number of neighbors
// }

// /*
// * Depth-First Search - DFS
// * Traverses all neighbors connected to the vertex first
// *
// */
// int depthFirstSearch(VERTEX start, VERTEX target, int visited) {
//     start->visited = true; // Mark the starting vertex as visited
//     if (start == target) return visited; // If it's the target, return the count of visited vertices

//     int aux = 0;
//     while (start->neighbors[aux] != NULL) { // While there are neighbors to visit
//         if (start->neighbors[aux]->visited == false) { // If the neighbor hasn't been visited yet
//             // Recursively call with the new neighbor as the start, traversing all its neighbors
//             int response = depthFirstSearch(start->neighbors[aux], target, visited + 1);
//             // If the return value is greater than -1, it means it found the target, so return the response
//             if (response != -1) return response;
//         }
//         aux++; // Increment the index in the neighbors list
//     }

//     return -1; // Target vertex not found
// }

// /*
// * Breadth-First Search - BFS
// * Implemented using a simple array as a queue
// * It does not remove the vertex from the array; it simply skips to the next position
// * Traverses all vertices level by level
// */
// int breadthFirstSearch(VERTEX start, VERTEX target) {
//     int startQueue = 0; // Variable to control the start position of the queue, used in the WHILE loop
//     int queueSize = 1; // Variable to control the size of the queue

//     VERTEX QUEUE[MAX_VERTICES]; // Queue that will hold vertices to be compared
//     for (int i = 0; i < MAX_VERTICES; i++) { // Since the list is not dynamic, it needs to be cleared first
//         QUEUE[i] = NULL;
//     }
//     QUEUE[startQueue] = start; // The first position of the queue receives the starting vertex

//     // While the queue is not empty
//     while (startQueue < queueSize) {
//         // If the vertex at the front of the queue is the target, return startQueue, the distance traveled
//         if (QUEUE[startQueue] == target) return startQueue;

//         /*
//         * For all neighbors of the vertex at the front of the queue:
//         * Mark all as visited so they are not added to the queue again,
//         * then add them to the queue and increase the size of the queue
//         */
//         for (int i = 0; i < QUEUE[startQueue]->numNeighbors; i++) {
//             if (QUEUE[startQueue]->neighbors[i]->visited == false) {
//                 QUEUE[startQueue]->neighbors[i]->visited = true; // Mark as visited
//                 QUEUE[queueSize] = QUEUE[startQueue]->neighbors[i]; // Add to the queue
//                 queueSize++; // Increment the queue size
//             }
//         }
//         startQueue++; // Increment the start of the queue, simulating removal of the first element (FIFO)
//     }
//     return -1; // Target vertex not found
// }

// int main() {
//     // Graph consisting of independent vertices
//     VERTEX A = createVertex('A');
//     VERTEX B = createVertex('B');
//     VERTEX C = createVertex('C');
//     VERTEX D = createVertex('D');
//     VERTEX E = createVertex('E');
//     VERTEX F = createVertex('F');

//     // Connect all vertices according to the graph presented in the introduction
//     connectVertices(A, B);
//     connectVertices(A, C);
//     connectVertices(B, D);
//     connectVertices(C, D);
//     connectVertices(B, E);
//     connectVertices(D, E);
//     connectVertices(E, F);
//     connectVertices(D, F);

//     // Perform depth-first search
//     int res = depthFirstSearch(A, F, 0);
//     if (res != -1)
//         printf("DFS - Found. Distance: %d.\n", res);
//     else
//         printf("DFS - Not found.\n");

//     // Reset all 'visited' attributes of all vertices to 'false'
//     A->visited = false;
//     B->visited = false;
//     C->visited = false;
//     D->visited = false;
//     E->visited = false;
//     F->visited = false;

//     // Perform breadth-first search
//     res = breadthFirstSearch(A, F);
//     if (res != -1)
//         printf("BFS - Found. Distance: %d.\n", res);
//     else
//         printf("BFS - Not found.\n");

//     // Graph consisting of vertices in an array
//     VERTEX GRAPH[MAX_VERTICES];
//     GRAPH[0] = createVertex('A');
//     GRAPH[1] = createVertex('B');
//     GRAPH[2] = createVertex('C');
//     GRAPH[3] = createVertex('D');
//     GRAPH[4] = createVertex('E');
//     GRAPH[5] = createVertex('F');

//     // Connect all vertices according to the graph presented in the introduction
//     connectVertices(GRAPH[0], GRAPH[1]);
//     connectVertices(GRAPH[0], GRAPH[2]);
//     connectVertices(GRAPH[1], GRAPH[3]);
//     connectVertices(GRAPH[2], GRAPH[3]);
//     connectVertices(GRAPH[1], GRAPH[4]);
//     connectVertices(GRAPH[3], GRAPH[4]);
//     connectVertices(GRAPH[4], GRAPH[5]);
//     connectVertices(GRAPH[3], GRAPH[5]);

//     // Perform depth-first search
//     res = depthFirstSearch(GRAPH[0], GRAPH[5], 0);
//     if (res != -1)
//         printf("DFS - Found. Distance: %d.\n", res);
//     else
//         printf("DFS - Not found.\n");

//     // Reset all 'visited' attributes of all vertices to 'false'
//     for (int i = 0; i < MAX_VERTICES; i++) {
//         GRAPH[i]->visited = false;
//     }

//     // Perform breadth-first search
//     res = breadthFirstSearch(GRAPH[0], GRAPH[5]);
//     if (res != -1)
//         printf("BFS - Found. Distance: %d.\n", res);
//     else
//         printf("BFS - Not found.\n");

//     return 0;
// }
