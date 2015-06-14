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