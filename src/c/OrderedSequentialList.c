/*
*	Exemplo de implementação de Lista Sequencial Ordenada em C - Utilizando sentinela
*	Kelvin S. do Prado - 2015
*/

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int TIPOCHAVE; // Define um nome TIPOCHAVE para um tipo inteiro

typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO A[MAX+1]; // O +1 é a posição que será utilizada para a 'sentinela'
	int nroElementos;
}LISTA;

void inicializar(LISTA* L){
	L->nroElementos = 0; // Acessa a lista pelo endereço de memória
	int i = 0;
	for (i; i < MAX-2; ++i){ // Preenche a lista até -2 para deixar espaço para inserir mais depois
		L->A[i].chave = i*2;
	}
	L->nroElementos = MAX-2;
	// (*L).nroElementos = 0; // Neste caso iria acessar a lista em si, e não o ponteiro
}

/* A função do sentinela é adicionar a chave ao final da lista, ou seja, 
 * sempre irá encontrar a chave, mesmo que seja na útlima posição da lista.
 * Caso seja o último elemento, significa que não encontrou.
 * Deste modo elimina o 'if' dentro do laço, poupando várias comparações
 */ 
int buscaSentinela(TIPOCHAVE ch, LISTA* L){ // Poderia usar aqui busca binária, o que seria mais apropriado.
	int i = 0;
	L->A[L->nroElementos].chave = ch; // Atribui a 'chave'/valor buscado a ultima posição do array A
	while(L->A[i].chave != ch) // Percorre todo o array A buscando se a 'chave'/valor pesquisado se encontra no array (senão será o sentinela)
		i++;
	if(i == L->nroElementos) // Se o valor chegou até o final, significa que não encontrou o valor, retorna ERRO (-1)
		return ERRO;
	return i; // Caso contrário retorna a posição do valor/'chave' no array
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

bool deletaValor(REGISTRO reg, LISTA* L){
	int posicao = buscaSentinela(reg.chave, L);
	if( posicao >= 0 ){
		for( posicao; posicao < L->nroElementos; posicao++ ){
			L->A[posicao] = L->A[posicao+1];
		}
		L->nroElementos--;
		return true;
	}else{
		return false;
	}
}

void mostraLista(LISTA* L){
	int i = 0;
	for (i; i < L->nroElementos; ++i){ // Percorre e mostra todos os valores do array
		printf("%d, ", L->A[i].chave);
	}
	printf("\n\n");
}

int main(){
	
	LISTA LISTA;
	inicializar(&LISTA);

	printf("Valor 10 encontrado na posição: %d\n\n", buscaSentinela(10, &LISTA) );
	mostraLista(&LISTA);

	REGISTRO reg;
	reg.chave = 7;
	printf("Insere o valor: %d\n", reg.chave);
	inserirOrdenado(reg, &LISTA);
	mostraLista(&LISTA);

	reg.chave = 12;
	printf("Deleta o valor: %d\n", reg.chave);
	deletaValor(reg, &LISTA);
	mostraLista(&LISTA);
	
	return 0;
}