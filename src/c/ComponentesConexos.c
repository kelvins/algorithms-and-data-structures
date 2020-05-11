/*
*
*	Grafos - Algoritmo para calcular o número de componentes conexos em um determinado Grafo
*	Kelvin Salton do Prado - 2015
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