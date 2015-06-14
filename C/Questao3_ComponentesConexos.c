/*
*
*	SIN5013 - Exemplo de Prova do Conteúdo Semestral
*
*	3. Escreva um programa (utilizando um ou mais métodos/funções em código ou pseudo-código) que dado um
*	grafo não direcionado com n nós retorne o número de componentes conexos do grafo. Este grafo pode ser
*	representado por: (a) uma matriz de adjacências booleana com n x n células correspondendo aos n nós do grafo;
*	ou representado por: (b) um arranjo de nós sendo que cada nó possui um arranjo de vizinhos; neste caso,
*	considere que Nó é uma classe ou estrutura que possui os seguintes campos [ou atributos]: numVizinhos
*	(campo do tipo inteiro com o número de vizinhos do respectivos nó), vizinhos (arranjo de ponteiros para Nós
*	com numVizinhos elementos), visitado (campo booleano). Escolha a representação que te convém, se desejar,
*	considere que todas as variáveis são globais/static. Assuma que as variáveis já estão devidamente
*	inicializadas/preenchidas.
*
*	Representação:
*	int numNos = n;
*	boolean adjacencias[][] = new boolean[n][n];
*	boolean visitados[] = new boolean[n];
*
*
*	GRAFO
*   (0)               (1)-------------(4)---------------(5)
*    |                 |               |                 |
*    |       (6)       |               |                 |
*    |                 |               |                 | 
*   (2)               (3)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*
*    Matriz de Adjacência
*       0  1  2  3  4  5  6
*    0  0  -  1  -  -  -  -
*    1  -  0  -  1  1  -  -
*    2  1  -  0  -  -  -  -
*    3  -  1  -  0  1  1  -
*    4  -  1  -  1  0  1  -
*	 5  -  -  -  1  1  0  -
*	 6  -  -  -  -  -  -  0
*
*/

#include <stdio.h>

#define nroNos 7
bool visitados[nroNos];
bool matriz[nroNos][nroNos]  = {{ false, false,  true, false, false, false, false },
								{ false, false, false,  true,  true, false, false },
								{  true, false, false, false, false, false, false },
								{ false,  true, false, false,  true,  true, false },
								{ false,  true, false,  true, false,  true, false },
								{ false, false, false,  true,  true, false, false },
								{ false, false, false, false, false, false, false }};
int componentes = 0;

void zeraVariaveis(){
	componentes = 0;
	for (int i = 0; i < nroNos; i++)
		visitados[i] = false;
}

void visitaVizinhos(int atual){
	for (int i = 0; i < nroNos; i++){
		if( visitados[i] == false && matriz[atual][i] == true ){
			visitados[i] = true;
			componentes++;
			printf("(%d)-", i);
			visitaVizinhos(i);
		}
	}
}

void calculaComponentesConexos(){
	// Percorre todos os 'nós'/'componentes'
	for (int i = 0; i < nroNos; i++){
		componentes = 0;
		if( visitados[i] == false ){ // Se o componente ainda não foi visitado
			visitaVizinhos(i); // Chama o método que conta as conexões com os vizinhos
			printf("Grupo %d:\nQuantidade de componentes conectados: %d\n\n", i, componentes);
		}
	}
}

int main(){

	zeraVariaveis();
	calculaComponentesConexos();

	return 0;
}