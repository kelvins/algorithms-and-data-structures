/*
*	Problema do Caixeiro Viajante em C
*	Utilizando uma matriz de distância para representar um grafo não direcionado.
*	Objetivo: Encontrar o menor caminho que passe por todos os vértices sem repetir nenhum, e chegar novamente ao vértice de início
*
*                      6
*                 (4)-----(0)
*                 |  \    / \ 
*                 |   \ 3/   \2 
*                 |    \/     \ 
*                3|    /\     (1)
*                 |   / 3\   4/ |
*                 |  /    \  /  |
*                 (3)-----(2)   |
*                  |   7        | 
*                  |            | 3
*                  --------------
*
*
*   Matriz de Distância
*       0  1  2  3  4 
*    0  0  2  -  3  6
*    1  2  0  4  3  -
*    2  -  4  0  7  3
*    3  3  3  7  0  3
*    4  6  -  3  3  0
*
*
*/

#include <stdio.h>

#define VERTICES 5
#define INFINITO 429496729

int tempSolucao[VERTICES];
int melhorSolucao[VERTICES];
bool visitados[VERTICES];
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;

int matriz[VERTICES][VERTICES]  = {{         0,          2,   INFINITO, 3,          6 },
								  {          2,          0,          4, 3,   INFINITO },
								  {   INFINITO,          4,          0, 7,          3 },
								  {          3,          3,          7, 0,          3 },
								  {          6,   INFINITO,          3, 3,          0 }};

void caixeiroViajanteAux(int x){
	// Se o valor da solução atual já estiver maior que o valor da melhor solução já para, pois já não pode mais ser a melhor solução
	if( valorSolucaoAtual > valorMelhorSolucao )
		return;

	if( x == VERTICES ){ // Se x == VERTICES significa que o vetor da solução temporária está completo
		int distancia = matriz[tempSolucao[x-1]][tempSolucao[0]];
		// Se encontrou uma solução melhor/menor
		if( distancia < INFINITO && valorSolucaoAtual + distancia < valorMelhorSolucao ){
			valorMelhorSolucao = valorSolucaoAtual + distancia; // Substitui a melhor solução pela melhor encontrada agora
			// Copia todo o vetor de solução temporária para o vetor de melhor solução encontrada
			for (int i = 0; i < VERTICES; ++i){
				melhorSolucao[i] = tempSolucao[i];
			}
		}
		return;
	}

	int ultimo = tempSolucao[x-1]; // Ultimo recebe o número do último vértice que se encontra na solução temporária
	// For que percorre todas as colunas da matriz na linha do último vértice do vetor solução temporária
	for (int i = 0; i < VERTICES; i++){
		// Se a posição i do vetor ainda não foi visitada, e se o valor da matriz na posição é menor que INFINITO
		if( visitados[i] == false && matriz[ultimo][i] < INFINITO ){
			visitados[i] = true; // Marca como visitado
			tempSolucao[x] = i; // Carrega o vértice que está passando no vetor de solução temporária
			valorSolucaoAtual += matriz[ultimo][i]; // Incrementa o valor da matriz na variável que guarda o total do caminho percorrido
			caixeiroViajanteAux(x+1); // Chama recursivamente para o próximo vértice
			valorSolucaoAtual -= matriz[ultimo][i]; // Se ainda não terminou, diminuí o valor da váriavel que guarda o total da solução atual
			visitados[i] = false; // Seta como false a posição para poder ser utilizado por outro vértice
		}

	}

}

void caixeiroViajante(int inicial){
	visitados[inicial] = true; // Marca o primeiro vértice como visitado (0)
	tempSolucao[0] = inicial; // Coloca o vértice 0 na primeira posição do vetor de solução temporária
	caixeiroViajanteAux(1); // Chama o método auxiliar do caixeiro viajante
}

void iniciaVetores(){
	for (int i = 0; i < VERTICES; i++){
		visitados[i] = false;
		tempSolucao[i] = -1;
		melhorSolucao[i] = -1;
	}
}

int main(){

	iniciaVetores();
	caixeiroViajante(0);

	printf("Caminho mínimo: %d\n", valorMelhorSolucao);
	for (int i = 0; i < VERTICES; i++){
		printf("%d, ", melhorSolucao[i]);
	}
	printf("\n\n");
}


//  In english 


/*
* Traveling Salesman Problem in C
* Using a distance matrix to represent an undirected graph.
* Objective: Find the shortest path that visits all vertices without repeating any and returns to the starting vertex.
*
*                      6
*                 (4)-----(0)
*                 |  \    / \ 
*                 |   \ 3/   \2 
*                 |    \/     \ 
*                3|    /\     (1)
*                 |   / 3\   4/ |
*                 |  /    \  /  |
*                 (3)-----(2)   |
*                  |   7        | 
*                  |            | 3
*                  --------------
*
*   Distance Matrix
*       0  1  2  3  4 
*    0  0  2  -  3  6
*    1  2  0  4  3  -
*    2  -  4  0  7  3
*    3  3  3  7  0  3
*    4  6  -  3  3  0
*/


// #define VERTICES 5
// #define INFINITY 429496729  // A large value representing infinity

// int tempSolution[VERTICES];
// int bestSolution[VERTICES];
// bool visited[VERTICES];
// int bestSolutionValue = INFINITY;
// int currentSolutionValue = 0;

// // Distance matrix representing the graph
// int matrix[VERTICES][VERTICES]  = {
//     {         0,          2,   INFINITY, 3,          6 },
//     {          2,          0,          4, 3,   INFINITY },
//     {   INFINITY,          4,          0, 7,          3 },
//     {          3,          3,          7, 0,          3 },
//     {          6,   INFINITY,          3, 3,          0 }
// };

// void travelingSalesmanAux(int x) {
//     // If the current solution value is already greater than the best solution value, stop since it can't be the best solution
//     if (currentSolutionValue > bestSolutionValue)
//         return;

//     if (x == VERTICES) { // If x == VERTICES means the temporary solution array is complete
//         int distance = matrix[tempSolution[x - 1]][tempSolution[0]];
//         // If a better solution is found
//         if (distance < INFINITY && currentSolutionValue + distance < bestSolutionValue) {
//             bestSolutionValue = currentSolutionValue + distance; // Update best solution value
//             // Copy the entire temporary solution array to the best solution array
//             for (int i = 0; i < VERTICES; ++i) {
//                 bestSolution[i] = tempSolution[i];
//             }
//         }
//         return;
//     }

//     int last = tempSolution[x - 1]; // Last vertex in the temporary solution array
//     // Loop through all columns of the matrix at the row of the last vertex in the temporary solution array
//     for (int i = 0; i < VERTICES; i++) {
//         // If position i in the array has not been visited, and if the matrix value at the position is less than INFINITY
//         if (!visited[i] && matrix[last][i] < INFINITY) {
//             visited[i] = true; // Mark as visited
//             tempSolution[x] = i; // Add the current vertex to the temporary solution array
//             currentSolutionValue += matrix[last][i]; // Increment the total path cost
//             travelingSalesmanAux(x + 1); // Recursively call for the next vertex
//             currentSolutionValue -= matrix[last][i]; // If not done yet, decrement the current solution value
//             visited[i] = false; // Mark as unvisited for use by another vertex
//         }
//     }
// }

// void travelingSalesman(int start) {
//     visited[start] = true; // Mark the first vertex as visited (0)
//     tempSolution[0] = start; // Put vertex 0 in the first position of the temporary solution array
//     travelingSalesmanAux(1); // Call the auxiliary method for the traveling salesman problem
// }

// void initializeVectors() {
//     for (int i = 0; i < VERTICES; i++) {
//         visited[i] = false;
//         tempSolution[i] = -1;
//         bestSolution[i] = -1;
//     }
// }

// int main() {
//     initializeVectors();
//     travelingSalesman(0);

//     printf("Minimum path cost: %d\n", bestSolutionValue);
//     for (int i = 0; i < VERTICES; i++) {
//         printf("%d, ", bestSolution[i]);
//     }
//     printf("\n\n");
// }
