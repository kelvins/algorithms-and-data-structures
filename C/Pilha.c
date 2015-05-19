/* 
*	Exemplo de implementação de Pilha em C - Utiliza Sentinela
*	Kelvin S. do Prado - 2015
*/

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO A[MAX+1];
	int nroRegistros;
}PILHA;

int inicializa(PILHA* p){
	p->nroRegistros = 0;
	int i = 0;
	for (i; i < MAX-2; i++){ // Preenche a Pilha *para testes
		p->A[i].chave = i*2; // É um array de REGISTRO (semelhante a class), poderia ter mais campos, por isso se define A[i].chave, irá inserir o valor no campo chave
	}
	p->nroRegistros = i;
}

bool inserePilha(int valor, PILHA* p){
	if( p->nroRegistros < MAX ){
		p->A[p->nroRegistros].chave = valor;
		p->nroRegistros++;
		return true;
	}else{
		return false;
	}
}

bool removePilha(PILHA* p){
	p->nroRegistros--;
}

void mostraPilha(PILHA* p){
	int i = p->nroRegistros-1;
	printf("\nPilha:\n");
	for (i; i >= 0; i--){
		printf("%d = [ %d ]\n", i, p->A[i].chave);
	}
	printf("------------------\n");
}

int buscaPilha(int chave, PILHA* p){
	p->A[p->nroRegistros].chave = chave;
	int aux = 0;
	while( p->A[aux].chave != chave )
		aux++;
	if( aux == p->nroRegistros )
		return ERRO;
	return aux;
}

int main(){
	PILHA vPilha;
	inicializa(&vPilha);

	mostraPilha(&vPilha);
	if( inserePilha(10, &vPilha) ){
		printf("Inserido com sucesso");
	}else{
		printf("Pilha cheia");
	}
	
	mostraPilha(&vPilha);
	removePilha(&vPilha);
	mostraPilha(&vPilha);
	
	int aux = buscaPilha(8, &vPilha);
	if( aux != -1 ){
		printf("Valor 8 encontrado na posicao %d da pilha\n", aux);
	}else{
		printf("Valor nao encontrado\n");
	}
}