#include <stdio.h>

#define MAX 50
#define ERRO -1

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO A[MAX+1]; // O +1 é a posição que será utilizado para o 'sentinela'
	int nroElementos;
}LISTA;

void inicializar(LISTA* L){
	L->nroElementos = 0; // Acessa a lista pelo endereço de memória
	// (*L).nroElementos = 0; // Neste caso iria acessar a lista em si, e não o ponteiro
}

/* A função do sentinela é adicionar a chave ao final da lista, ou seja, 
 * sempre irá encontrar a chave, mesmo que seja na útlima posição da lista.
 * Caso seja o último elemento, significa que não encontrou.
 * Deste modo elimina o 'if' dentro do laço, poupando várias comparações
 */ 
int buscaSentinela(TIPOCHAVE ch, LISTA* L){ // Poderia usar aqui busca binária, o que seria mais apropriado.
	int i = 0;
	L->A[L->nroElementos].chave = ch;
	while(L->A[i].chave != ch) 
		i++;
	if(i == L->nroElementos)
		return ERRO;
	return i;
}

bool inserirOrdenado(REGISTRO reg, LISTA* L){
	int i = 0;
	if(L->nroElementos >= MAX)
		return false;
	L->A[L->nroElementos].chave = reg.chave;
	while(L->A[i].chave < reg.chave)
		i++;
	int p = L->nroElementos-1;
	while(p >= i){
		L->A[p+1] = L->A[p];
		p--;
	}
	L->A[i] = reg;
	L->nroElementos++;
	return true;
}

int main(){
	printf("ok");
	return 0;
}