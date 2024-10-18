/*
*	Exemplo de implementação de Fila em C
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
}FILA;

void inicializa(FILA* F){
	int i = 0;
	for (i; i < MAX-2; i++){
		F->A[i].chave = i*2;
	}
	F->nroRegistros = i;
}

void mostraFila(FILA* F){
	int i = 0;
	printf("FILA:\n");
	for (i; i < F->nroRegistros; i++){
		printf("[ %d ] ", F->A[i].chave);
	}
	printf("\n\n");
}

bool insereFila(TIPOCHAVE ch, FILA* F){
	if( F->nroRegistros >= MAX )
		return false;
	F->A[F->nroRegistros].chave = ch;
	F->nroRegistros++;
	return true;
}

bool removeFila(FILA* F){
	if( F->nroRegistros <= 0 )
		return false;
	int i = 1;
	for (i; i < F->nroRegistros; i++){
		F->A[i-1].chave = F->A[i].chave;
	}
	F->nroRegistros--;
	return true;
}

int buscaFila(TIPOCHAVE ch, FILA* F){
	F->A[F->nroRegistros].chave = ch; // Coloca a ch na ultima posição para fazer busca Sentinela
	int i = 0;
	while( F->A[i].chave != ch )
		i++;
	if( i >= F->nroRegistros )
		return ERRO;
	return i;
}

int main(){
	FILA fi;
	inicializa(&fi);
	mostraFila(&fi);

	insereFila(15, &fi);
	mostraFila(&fi);

	removeFila(&fi);
	mostraFila(&fi);

	printf("A chave buscada se encontra na posicao %d da fila\n\n", buscaFila(8, &fi) );
	return 0;
}


//  In english
/*
* Example implementation of a Queue in C
*/


// #define MAX 10
// #define ERROR -1

// typedef int KEY_TYPE;

// typedef struct {
//     KEY_TYPE key; // The key of the record
// } RECORD;

// typedef struct {
//     RECORD A[MAX + 1]; // Array to store the queue records
//     int numRecords; // Number of records in the queue
// } QUEUE;

// // Function to initialize the queue
// void initialize(QUEUE* Q) {
//     int i = 0;
//     // Initialize the queue with even numbers
//     for (i; i < MAX - 2; i++) {
//         Q->A[i].key = i * 2; // Store even numbers
//     }
//     Q->numRecords = i; // Set the number of records
// }

// // Function to display the queue
// void showQueue(QUEUE* Q) {
//     int i = 0;
//     printf("QUEUE:\n");
//     // Print all elements in the queue
//     for (i; i < Q->numRecords; i++) {
//         printf("[ %d ] ", Q->A[i].key);
//     }
//     printf("\n\n");
// }

// // Function to insert a key into the queue
// bool insertQueue(KEY_TYPE key, QUEUE* Q) {
//     if (Q->numRecords >= MAX) // Check if the queue is full
//         return false;
//     Q->A[Q->numRecords].key = key; // Insert the key at the end
//     Q->numRecords++; // Increment the number of records
//     return true;
// }

// // Function to remove an element from the queue
// bool removeQueue(QUEUE* Q) {
//     if (Q->numRecords <= 0) // Check if the queue is empty
//         return false;
//     int i = 1;
//     // Shift all elements to the front
//     for (i; i < Q->numRecords; i++) {
//         Q->A[i - 1].key = Q->A[i].key; // Move the elements
//     }
//     Q->numRecords--; // Decrement the number of records
//     return true;
// }

// // Function to search for a key in the queue
// int searchQueue(KEY_TYPE key, QUEUE* Q) {
//     Q->A[Q->numRecords].key = key; // Place the key at the end for sentinel search
//     int i = 0;
//     // Search for the key
//     while (Q->A[i].key != key)
//         i++;
//     if (i >= Q->numRecords) // If the key was not found
//         return ERROR;
//     return i; // Return the index where the key was found
// }

// int main() {
//     QUEUE q; // Declare the queue
//     initialize(&q); // Initialize the queue
//     showQueue(&q); // Display the queue

//     insertQueue(15, &q); // Insert a new key
//     showQueue(&q); // Display the updated queue

//     removeQueue(&q); // Remove the front element
//     showQueue(&q); // Display the queue after removal

//     printf("The searched key is located at position %d in the queue\n\n", searchQueue(8, &q));
//     return 0;
// }
