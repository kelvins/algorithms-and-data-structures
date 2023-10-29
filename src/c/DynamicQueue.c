/*
*	Implementação de uma Estrutura de Fila Dinâmica Ligada/Encadeada em C
*	Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct NO{
	TIPOCHAVE chave;
	struct NO* prox;
}*PONT;

PONT novoNO(TIPOCHAVE ch){
	PONT aux = (PONT) malloc( sizeof(NO) );
	aux->chave = ch;
	aux->prox  = NULL;
	return aux;
}

PONT insere(TIPOCHAVE ch, PONT no){
	PONT aux = novoNO(ch);
	aux->prox = no;
	return aux;
}

void mostraFila(PONT no){
	while(no != NULL){
		printf("[%d]->", no->chave);
		no = no->prox;
	}
	printf("\n");
}

void remove(PONT no){
	PONT noAnterior = no;
	while(no->prox != NULL){
		noAnterior = no;
		no = no->prox;
	}	
	noAnterior->prox = NULL;
	free(no);
}

int tamanhoFila(PONT no){
	int cont = 0;
	while(no != NULL){
		cont++;
		no = no->prox;
	}	
	return cont;
}

int main(){
	PONT fila = novoNO(5);
	fila = insere(8, fila);
	fila = insere(1, fila);
	fila = insere(3, fila);
	fila = insere(5, fila);
	fila = insere(4, fila);
	fila = insere(2, fila);

	mostraFila(fila);
	remove(fila);
	mostraFila(fila);
	remove(fila);
	mostraFila(fila);

	printf("Tamanho da fila: %d\n", tamanhoFila(fila) );
	return 0;
}