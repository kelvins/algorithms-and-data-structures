/*
*	Exemplo de implementação de Lista Sequencial Ordenada em C - Utilizando sentinela
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


// In english 

/*
* Example implementation of a Sorted Sequential List in C - Using Sentinel
*/


// #define MAX 10
// #define ERROR -1

// typedef int KEYTYPE; // Define a name KEYTYPE for an integer type

// typedef struct {
//     KEYTYPE key;
// } RECORD;

// typedef struct {
//     RECORD A[MAX + 1]; // The +1 is the position that will be used for the 'sentinel'
//     int numElements;
// } LIST;

// void initialize(LIST* L) {
//     L->numElements = 0; // Access the list by its memory address
//     int i = 0;
//     for (i; i < MAX - 2; ++i) { // Fill the list up to -2 to leave space for future insertions
//         L->A[i].key = i * 2;
//     }
//     L->numElements = MAX - 2;
//     // (*L).numElements = 0; // In this case, it would access the list itself, not the pointer
// }

// /* The purpose of the sentinel function is to add the key at the end of the list, 
//  * so it will always find the key, even if it's in the last position of the list.
//  * If it's the last element, it means it wasn't found.
//  * Thus, this eliminates the 'if' inside the loop, saving several comparisons
//  */
// int sentinelSearch(KEYTYPE ch, LIST* L) { // Could use binary search here, which would be more appropriate.
//     int i = 0;
//     L->A[L->numElements].key = ch; // Assigns the 'key'/searched value to the last position of array A
//     while (L->A[i].key != ch) // Traverses the entire array A to check if the 'key'/searched value is in the array (otherwise it will be the sentinel)
//         i++;
//     if (i == L->numElements) // If the value reached the end, it means it wasn't found, return ERROR (-1)
//         return ERROR;
//     return i; // Otherwise, return the position of the value/'key' in the array
// }

// bool insertOrdered(RECORD reg, LIST* L) {
//     int i = 0;
//     if (L->numElements >= MAX)
//         return false;
//     L->A[L->numElements].key = reg.key;
//     while (L->A[i].key < reg.key)
//         i++;
//     int p = L->numElements - 1;
//     while (p >= i) {
//         L->A[p + 1] = L->A[p];
//         p--;
//     }
//     L->A[i] = reg;
//     L->numElements++;
//     return true;
// }

// bool deleteValue(RECORD reg, LIST* L) {
//     int position = sentinelSearch(reg.key, L);
//     if (position >= 0) {
//         for (position; position < L->numElements; position++) {
//             L->A[position] = L->A[position + 1];
//         }
//         L->numElements--;
//         return true;
//     } else {
//         return false;
//     }
// }

// void showList(LIST* L) {
//     int i = 0;
//     for (i; i < L->numElements; ++i) { // Traverses and shows all values in the array
//         printf("%d, ", L->A[i].key);
//     }
//     printf("\n\n");
// }

// int main() {
    
//     LIST LISTA;
//     initialize(&LISTA);

//     printf("Value 10 found at position: %d\n\n", sentinelSearch(10, &LISTA));
//     showList(&LISTA);

//     RECORD reg;
//     reg.key = 7;
//     printf("Inserting value: %d\n", reg.key);
//     insertOrdered(reg, &LISTA);
//     showList(&LISTA);

//     reg.key = 12;
//     printf("Deleting value: %d\n", reg.key);
//     deleteValue(reg, &LISTA);
//     showList(&LISTA);
    
//     return 0;
// }
