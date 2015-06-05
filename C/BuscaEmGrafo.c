/*
*
*	Grafos - Implementação de uma estrutura de Grafo não dirigido em C
*	Métodos de Busca: Busca em Profundidade e Busca em Largura
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