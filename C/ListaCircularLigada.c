/*
*
*	Lista Ligada com Nó Cabeça, Circular e Ordenada (Implementação Dinâmica)
*	Kelvin Salton do Prado - 2015
*
*/

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE; // Tipo de ID de cada nó da lista

// Estrutura de dados que representa cada nó da lista
typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX* prox;
}NO, *PONT;

typedef struct{
	PONT cab; // Nó cabeça
}LISTA;

void inicializar(LISTA *L){
	// Nó cabeça não deixa a lista ficar vazia, também pode ser usado como sentinela
	L->cab = (PONT) malloc( sizeof(NO) );
	L->cab->prox = L->cab; // Começa apontando para o próprio nó, pois é circular
}

// Como neste método não irá alterar a lista, pode ser passado uma cópia dela e não necessáriamente um ponteiro para ela
PONT buscaSequencial(TIPOCHAVE ch, LISTA L, PONT* ant){
	*ant = L.cab; // Sendo uma cópia pode-se usar o ponto (.) no lugar de seta (->), o ant guarda o ponteiro para o nó encontrado
	PONT pos = L.cab->prox;
	L.cab->chave = ch; // Grava o valor no nó cabeça para ser utilizado como sentinela, será o último a ser comparado
	while(pos->chave != ch){ 
		*ant = pos; // Guarda o ponteiro para o nó
		pos = pos->prox; // Vai para o próximo nó
	}
	if( pos != L.cab ) // Se o nó não é o nó cabeça é pq encontrou
		return pos; // Retorna o nó
	else
		return NULL; // Senão não encontrou retorna NULL
}

bool excluir(TIPOCHAVE ch, LISTA *L){
	PONT aux, ant;
	aux = buscaSequencial(ch, *L, &ant); // Busca o valor para excluir, o ant é passado como endereço de memória, assim a função busca altera ele, guardando o valor anterior
	if( aux == NULL ) return false; // Não encontrou
	ant->prox = aux->prox; // Nó anterior aponta para o próximo, no caso o próximo que o nó a ser excluído está apontando
	free(aux); // Libera a memória
	return true;
}

void inserir(TIPOCHAVE ch, LISTA *L){
	PONT ant = L->cab; // O ant guarda o ponteiro para o nó anterior
	PONT pos = L->cab->prox; // O pos guarda o ponteiro para o atual

	while(pos->chave < ch && pos != L->cab){
		ant = pos; // Guarda o ponteiro para o nó atual, que será o anterior
		pos = pos->prox; // Vai para o próximo nó
	}
	// Quando encontrou a posição correta na ordem crescente
	PONT novo_no = (PONT) malloc( sizeof(NO) ); // Cria um novo nó
	novo_no->chave = ch; // Coloca a chave no nó
	novo_no->prox  = pos; // Aponta para o próximo nó
	ant->prox = novo_no; // Nó anterior aponta para o novo nó
}

PONT mostrarLista(LISTA L){
	PONT pos = L.cab->prox; // Pos recebe o primeiro elemento depois do nó cabeça
	while(pos != L.cab){ // Se não for o nó cabeça, a lista não está vazia
		printf("[ %d ]->", pos->chave); // Mostra o valor do nó
		pos = pos->prox; // Vai para o próximo nó
	}printf("\n");
}

int main(){
	
	LISTA lista;
	inicializar(&lista);

	inserir(4, &lista);
	inserir(6, &lista);
	inserir(2, &lista);
	inserir(3, &lista);
	inserir(1, &lista);
	inserir(5, &lista);

	mostrarLista(lista);

	excluir(2, &lista);
	excluir(4, &lista);
	excluir(6, &lista);

	mostrarLista(lista);

	// Exemplo de busca na lista
	PONT aux;
	int valor = 2;
	if( buscaSequencial(valor, lista, &aux) != NULL )
		printf("Valor %d encontrado.\n", valor );
	else
		printf("Valor %d não encontrado.\n", valor);

	return 0;
}