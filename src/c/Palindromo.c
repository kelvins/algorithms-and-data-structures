#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
* Problema do palindromo
* Desenvolvido por Igor Alves (https://github.com/iguit0)
*/

typedef struct sCell{
	char info;
	struct sCell* next;
}CELULA;

typedef struct sPilha{
	CELULA* topo;	
}PILHA;

CELULA* criarCelula(){
	CELULA* nova;
	nova = (CELULA *) malloc(sizeof(CELULA));
	return nova;
}

void inicializar(PILHA* p){
	p->topo = NULL;
}

int pilhaVazia(PILHA* p){
	if(p->topo == NULL) return 1;
	else return 0;
}

int push(PILHA* p,char elemento){
	CELULA* nova = criarCelula();
	if(nova == NULL) return 0;
	nova->info = elemento;
	nova->next = p->topo;
	if(pilhaVazia(p)){
		p->topo = nova;
		return 1;
	}
	p->topo = nova;
	return 1;
}

char pop(PILHA* p){
	CELULA* removida;
	char removido;
	if(pilhaVazia(p)){
		printf("\nPilha Vazia!");
		return removido;
	}
	removida = p->topo;
	removido = removida->info;
	p->topo = p->topo->next;
	free(removida);
	return removido;
}

int palindromo(PILHA* p){
	if(pilhaVazia(p)){
		printf("Pilha Vazia!\n");
		return 0;
	}
	PILHA p2;
	inicializar(&p2);
	PILHA p3;
	inicializar(&p3);
	char aux; 		
	char aux2;
	while(!pilhaVazia(p)){
		aux = pop(p);
		if(aux != '.' && aux != ' '){
			push(&p2,aux);
		}
	}
	while(!pilhaVazia(&p2)){
		aux = pop(&p2);
		push(p,aux);
		push(&p3,aux);
	}
	while(!pilhaVazia(&p3)){
		aux = pop(&p3);
		push(&p2,aux);
	}
	while(!pilhaVazia(p)){
		aux = pop(p);
		aux2 = pop(&p2);
		if(aux != aux2){
			return 0;
		}
	}
	return 1;
}

void imprimirInverso(PILHA* p){
	PILHA p2;
	inicializar(&p2);
	char aux;
	if(pilhaVazia(p)) return;
	while(!pilhaVazia(p)){
		aux = pop(p);
		putchar(aux);
		push(&p2,aux);
	}
	while(!pilhaVazia(&p2))
		push(p,pop(&p2));
	
}

int main(){
    PILHA p;
    inicializar(&p);
    int i=0;
	char palavra[100];	
	char inverso[100];
	printf("\nPalavra: ");
	scanf("%s",palavra);
	
	for(i=0;i<strlen(palavra);i++){
		push(&p,palavra[i]);
	}
	
	printf("\nImprimindo inverso > ");
	imprimirInverso(&p);
	putchar('\n');
	
	if(palindromo(&p)==1) printf("\nPalindromo");
	else printf("\nNao eh palindromo");

    return 0;
}
