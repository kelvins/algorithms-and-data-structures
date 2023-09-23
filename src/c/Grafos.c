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

#define MAX_VERTICES 20 // Constant that defines the maximum number of vertices the graph can have

int nroVertices = 0; // Stores the current number of vertices
int matriz[MAX_VERTICES][MAX_VERTICES]; // Distance Matrix
int componentes;

typedef struct NO {
	char id;
	int nroVizinhos;
	struct AUX* vizinhos[];
	bool visited;
	int indice; // Stores the order in which the vertex was created
} * VERTICE;

typedef struct AUX {
	VERTICE vizinho;
	int valor;
} * ARESTA;

VERTICE criaVertice(char id) {
	matriz[nroVertices][nroVertices] = 0;
	VERTICE novo = (VERTICE)malloc(sizeof(NO));
	novo->id = id;
	novo->nroVizinhos = 0;
	novo->visited = false;
	novo->indice = nroVertices;
	nroVertices++;
	return novo;
}

void ligaVertice(VERTICE v1, VERTICE v2, int valor) {
	matriz[v1->indice][v2->indice] = valor;
	ARESTA nova = (ARESTA)malloc(sizeof(AUX));
	nova->vizinho = v2;
	nova->valor = valor;
	v1->vizinhos[v1->nroVizinhos] = nova;
	v1->nroVizinhos++;
}

void mostraMatrizDistancia() {
	printf("\nDistance Matrix\n");
	for (int l = 0; l < nroVertices; l++) {
		for (int c = 0; c < nroVertices; c++) {
			if (matriz[l][c] == -1)
				printf("%d, ", matriz[l][c]);
			else
				printf(" %d, ", matriz[l][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void zeraVariaveis() {
	for (int l = 0; l < MAX_VERTICES; l++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			matriz[l][c] = -1;
		}
	}
}

void visitNeighbors(bool visited[], int current) {
	for (int i = 0; i < nroVertices; i++) {
		if (visited[i] == false && matriz[current][i] > 0) {
			visited[i] = true;
			componentes++;
			visitNeighbors(visited, i);
		}
	}
}

void calculateConnectedComponents() {
	bool visited[nroVertices];
	for (int i = 0; i < nroVertices; ++i) {
		visited[i] = false;
	}
	for (int i = 0; i < nroVertices; i++) {
		if (visited[i] == false) {
			visitNeighbors(visited, i);
		}
	}
}

int main() {
	zeraVariaveis();

	// The Distance Matrix works according to the order of insertion
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

	calculateConnectedComponents();
	printf("\nConnected Components: %d\n", componentes);

	mostraMatrizDistancia();

	return 0;
}
