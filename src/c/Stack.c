/* 
*	Exemplo de implementação de Pilha em C - Utiliza Sentinela
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


// In english 

/* 
* Example implementation of a Stack in C - Uses Sentinel
*/


// #define MAX 10
// #define ERROR -1

// typedef int KEYTYPE;

// typedef struct {
//     KEYTYPE key;
// } RECORD;

// typedef struct {
//     RECORD A[MAX + 1];
//     int numRecords;
// } STACK;

// int initialize(STACK* p) {
//     p->numRecords = 0;
//     int i = 0;
//     for (i; i < MAX - 2; i++) { // Fill the Stack for testing
//         p->A[i].key = i * 2; // It's an array of RECORD (similar to a class); it could have more fields, hence A[i].key, it will insert the value in the key field
//     }
//     p->numRecords = i;
// }

// bool insertStack(int value, STACK* p) {
//     if (p->numRecords < MAX) {
//         p->A[p->numRecords].key = value;
//         p->numRecords++;
//         return true;
//     } else {
//         return false;
//     }
// }

// bool removeStack(STACK* p) {
//     p->numRecords--;
// }

// void showStack(STACK* p) {
//     int i = p->numRecords - 1;
//     printf("\nStack:\n");
//     for (i; i >= 0; i--) {
//         printf("%d = [ %d ]\n", i, p->A[i].key);
//     }
//     printf("------------------\n");
// }

// int searchStack(int key, STACK* p) {
//     p->A[p->numRecords].key = key;
//     int aux = 0;
//     while (p->A[aux].key != key)
//         aux++;
//     if (aux == p->numRecords)
//         return ERROR;
//     return aux;
// }

// int main() {
//     STACK vStack;
//     initialize(&vStack);

//     showStack(&vStack);
//     if (insertStack(10, &vStack)) {
//         printf("Inserted successfully");
//     } else {
//         printf("Stack is full");
//     }
    
//     showStack(&vStack);
//     removeStack(&vStack);
//     showStack(&vStack);
    
//     int aux = searchStack(8, &vStack);
//     if (aux != -1) {
//         printf("Value 8 found at position %d in the stack\n", aux);
//     } else {
//         printf("Value not found\n");
//     }
// }
