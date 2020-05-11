/*
*	Exemplo de Lista Ligada Dinâmica Não Ordenada em C
*	Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <malloc.h>

#define ERRO -1

typedef int TIPOCHAVE;

typedef struct aux{
	TIPOCHAVE chave;
	struct aux *prox;
}REGISTRO, *PONT;

PONT criaRegistro(TIPOCHAVE ch){
	PONT rg = (PONT) malloc( sizeof(PONT) );
	rg->chave = ch;
	rg->prox = NULL;
	return rg;
}

PONT insereRegistro(TIPOCHAVE ch, PONT rg){
	if( rg == NULL ) 
		return criaRegistro(ch); // Se não tem nenhum registro na lista cria um novo
	while( rg->prox != NULL )
		rg = rg->prox;
	rg->prox = criaRegistro(ch);
	return NULL;
}

void mostraLista(PONT rg){
	if( rg == NULL ) return;
	printf("%d, ", rg->chave);
	mostraLista(rg->prox);
}

PONT buscaSequencial(TIPOCHAVE ch, PONT rg){
	while( rg != NULL ){
		if( rg->chave == ch )
			return rg;
		rg = rg->prox;
	}
	return NULL;
}

bool deletaRegistro(TIPOCHAVE ch, PONT rg){
	PONT ant;
	while( rg != NULL ){
		if( rg->chave == ch ){
			ant->prox = rg->prox;
			free(rg);
			return true;
		}
		ant = rg;
		rg = rg->prox;
	}
	printf("\nChave %d não encontrada.\n",ch);
	return false;	
}

int main(){
	PONT RG = insereRegistro(23, RG);
	insereRegistro(34, RG);
	insereRegistro(12, RG);
	insereRegistro(63, RG);
	insereRegistro(45, RG);

	mostraLista(RG);

	TIPOCHAVE ch = 64;
	if( buscaSequencial(ch, RG) != NULL )
		printf("\nEncontrou chave %d\n", ch);
	else
		printf("\nNão encontrou chave %d\n", ch);

	deletaRegistro(63, RG);
	mostraLista(RG);
	
	printf("\n");
	deletaRegistro(34, RG);
	mostraLista(RG);
	return 0;
}