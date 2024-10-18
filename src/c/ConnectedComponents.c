/*
*
*	Grafos - Algoritmo para calcular o número de componentes conexos em um determinado Grafo
*
*	GRAFO
*   (0)               (1)-------------(4)---------------(5)
*    |                 |               |                 |
*    |                 |               |                 |
*    |                 |               |                 | 
*   (2)               (3)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*
*    Matriz de Adjacência
*       0  1  2  3  4  5 
*    0  0  -  1  -  -  -
*    1  -  0  -  1  1  -
*    2  1  -  0  -  -  -
*    3  -  1  -  0  1  1
*    4  -  1  -  1  0  1
*	 5  -  -  -  1  1  0
*
*
*	6 Vértices
*	8 Arestas
*/

#include <stdio.h>

#define VERTICES 6
#define INF -1

bool visitados[VERTICES];
int componentes = 0;

int matriz[VERTICES][VERTICES]  = { {   0, INF,   1, INF, INF, INF },
									{ INF,   0, INF,   1,   1, INF },
									{   1, INF,   0, INF, INF, INF },
									{ INF,   1, INF,   0,   1,   1 },
									{ INF,   1, INF,   1,   0,   1 },
									{ INF, INF, INF,   1,   1,   0 } };

// Método recursivo que encontra os componentes conexos a partir de uma matriz de adjacências
void calculaComponentesConexos(int atual){
	for (int i = 0; i < VERTICES; i++){
		if( visitados[i] == false && matriz[atual][i] == 1 ){
			visitados[i] = true;
			componentes++;
			printf("(%d)-", i);
			calculaComponentesConexos(i);
		}
	}
}

int main(){
	for (int i = 0; i < VERTICES; i++)
		visitados[i] = false;

	for (int i = 0; i < VERTICES; i++)
		if( visitados[i] == false ){
			componentes = 0;
			calculaComponentesConexos(i);
			printf("\nNumero de componentes conexos iniciando pelo vertice %d: %d\n\n", i, componentes);
		}
	
	return 0;
}




/*
*
*	Graphs - Algorithm to calculate the number of connected components in a given Graph
*
*	GRAPH
*   (0)               (1)-------------(4)---------------(5)
*    |                 |               |                 |
*    |                 |               |                 |
*    |                 |               |                 | 
*   (2)               (3)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*
*    Adjacency Matrix
*       0  1  2  3  4  5 
*    0  0  -  1  -  -  -
*    1  -  0  -  1  1  -
*    2  1  -  0  -  -  -
*    3  -  1  -  0  1  1
*    4  -  1  -  1  0  1
*	 5  -  -  -  1  1  0
*
*
*	6 Vertices
*	8 Edges
*/

// #define VERTICES 6
// #define INF -1

// bool visited[VERTICES];
// int componentCount = 0;

// int adjacencyMatrix[VERTICES][VERTICES] = {
//     {0, INF, 1, INF, INF, INF},
//     {INF, 0, INF, 1, 1, INF},
//     {1, INF, 0, INF, INF, INF},
//     {INF, 1, INF, 0, 1, 1},
//     {INF, 1, INF, 1, 0, 1},
//     {INF, INF, INF, 1, 1, 0}
// };

// // Recursive method that finds connected components from an adjacency matrix
// void calculateConnectedComponents(int current) {
//     for (int i = 0; i < VERTICES; i++) {
//         if (!visited[i] && adjacencyMatrix[current][i] == 1) {
//             visited[i] = true;
//             componentCount++;
//             printf("(%d)-", i);
//             calculateConnectedComponents(i);
//         }
//     }
// }

// int main() {
//     for (int i = 0; i < VERTICES; i++)
//         visited[i] = false;

//     for (int i = 0; i < VERTICES; i++)
//         if (!visited[i]) {
//             componentCount = 0;
//             calculateConnectedComponents(i);
//             printf("\nNumber of connected components starting from vertex %d: %d\n\n", i, componentCount);
//         }

//     return 0;
// }
