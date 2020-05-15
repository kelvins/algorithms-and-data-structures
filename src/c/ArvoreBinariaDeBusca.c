/*
*	Árvore Binária de Busca em C
*	Kelvin Salton do Prado - 2015
*
*		 ( 6 )
*	     /   \
*	 ( 2 )   ( 7 )
* 	 /   \		\
*( 1 )   ( 4 )	( 8 )
*		 /   \
*	 ( 3 )	 ( 5 )
*/

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX *esq, *dir;
}NO, *PONT; // NO é a estrutura e PONT é um ponteiro de NO

int max(int a, int b){
	if( a > b )
		return a;
	return b;
}

int altura(PONT no){
	if( no == NULL ) // Mesma coisa que usar if(!no)
		return 0;
	return 1 + max( altura(no->esq), altura(no->dir) ); // Percorre a arvore pela esquerda e pela direita para ver qual tem altura maior
}

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
	if( !raiz )
		return NULL;
	if( raiz->chave == ch )
		return raiz;
	if( raiz->chave < ch )
		buscaBinaria(ch, raiz->dir);
	else
		buscaBinaria(ch, raiz->esq);
}

PONT buscaBinariaLinear(TIPOCHAVE ch, PONT atual){
	while( atual != NULL ){
		if( atual->chave == ch )
			return atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return NULL;
}

PONT criaNo(TIPOCHAVE ch){
	PONT no = (PONT) malloc( sizeof(NO) );
	no->esq = NULL;
	no->dir = NULL;
	no->chave = ch;
	return no;
}

bool inserir(TIPOCHAVE ch, PONT atual){
	PONT ant;
	// Percorre a arvore para a direita ou esquerda até encontrar uma posição NULL (vazia)
	while(atual != NULL){
		ant = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	atual = criaNo(ch); // Utiliza a váriavel atual, pois estava 'sobrando'
	if( ant->chave < ch )
		ant->dir = atual;
	else
		ant->esq = atual;
	return true;
}

PONT buscaNoPai(TIPOCHAVE ch, PONT atual){
	PONT noPai = atual;
	while( atual != NULL ){
		if( atual->chave == ch )
			return noPai;
		noPai = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return noPai;
}

PONT maiorAesquerda(PONT atual){
	atual = atual->esq;
	while( atual->dir != NULL )
		atual = atual->dir;
	return atual;
}

bool excluir(TIPOCHAVE ch, PONT raiz){
	PONT atual, noPai, substituto, paiSubstituto;
	substituto = NULL;
	atual = buscaBinaria(ch, raiz);
	if( atual == NULL ) return false; // Não encontrou a chave
	noPai = buscaNoPai(ch, raiz);
	if( atual->esq == NULL || atual->dir == NULL ){ // Se tem 0 ou 1 filho
		if( atual->esq == NULL )
			substituto = atual->dir;
		else
			substituto = atual->esq;
		if( noPai == NULL ){ // Único que não tem pai é a raiz
			raiz = substituto;
		}else{
			if( ch < noPai->chave)
				noPai->esq = substituto;
			else
				noPai->dir = substituto;
		}
		free(atual);
	}else{
		substituto = maiorAesquerda(atual);
		atual->chave = substituto->chave;
		if( substituto->esq != NULL )
			atual->esq = substituto->esq;
		else
			atual->esq = NULL;
		free(substituto);
	}
	return true;
}

void preordem(PONT no){ // R - E - D
	if( !no ) return;
	printf("%d, ", no->chave);
	preordem(no->esq);
	preordem(no->dir);
}

void posordem(PONT no){ // E - D - R
	if( !no ) return;
	posordem(no->esq);
	posordem(no->dir);
	printf("%d, ", no->chave);
}

void emordem(PONT no){ // E - R - D
	if( !no ) return;
	emordem(no->esq);
	printf("%d, ", no->chave);
	emordem(no->dir);
}

// Esta função não está funcionando
bool insereRecursivo(TIPOCHAVE ch, PONT no){
	PONT ant;
	if( !no ){
		no = criaNo(ch);
	}else{
		ant = no;
		if( ch < no->chave )
			insereRecursivo(ch, no->esq);
		else
			insereRecursivo(ch, no->dir);
	}
	if( ant->chave < ch )
		ant->dir = no;
	else
		ant->esq = no;
	return true;
}

int main(){
	PONT noArvore = criaNo(6);

	inserir(2, noArvore);
	inserir(1, noArvore);
	inserir(4, noArvore);
	inserir(7, noArvore);
	inserir(8, noArvore);
	inserir(3, noArvore);
	inserir(5, noArvore);

	int valorBuscado = 7;
	if( buscaBinaria(valorBuscado, noArvore) )
		printf("Busca : %d\n", buscaBinaria(valorBuscado, noArvore)->chave );
	else
		printf("Não encontrou\n");

	excluir(4, noArvore);

	printf("Pre-ordem: ");
	preordem(noArvore);
	printf("\n");
	printf("Em-ordem: ");
	emordem(noArvore);
	printf("\n");
	printf("Pos-ordem: ");
	posordem(noArvore);

	printf("\nAltura: %d\n", altura(noArvore) );
	return 0;
}