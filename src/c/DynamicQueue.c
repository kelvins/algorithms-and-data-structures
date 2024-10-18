/*
*	Implementação de uma Estrutura de Fila Dinâmica Ligada/Encadeada em C
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



/*
* Implementation of a Dynamic Linked Queue in C
*/

// typedef int KEYTYPE; // Define KEYTYPE as an integer

// typedef struct NODE {
// 	KEYTYPE key; // The key/value of the node
// 	struct NODE* next; // Pointer to the next node
// }* POINTER; // Define POINTER as a pointer to a NODE

// // Create a new node with the given key
// POINTER newNode(KEYTYPE ch) {
// 	POINTER aux = (POINTER) malloc(sizeof(NODE)); // Allocate memory for a new node
// 	aux->key = ch; // Set the key of the new node
// 	aux->next = NULL; // Initialize the next pointer to NULL
// 	return aux; // Return the new node
// }

// // Insert a new node at the beginning of the queue
// POINTER insert(KEYTYPE ch, POINTER node) {
// 	POINTER aux = newNode(ch); // Create a new node
// 	aux->next = node; // Set the next pointer of the new node to the current node
// 	return aux; // Return the new head of the queue
// }

// // Display the elements of the queue
// void showQueue(POINTER node) {
// 	while (node != NULL) { // Traverse the queue
// 		printf("[%d]->", node->key); // Print the key of the current node
// 		node = node->next; // Move to the next node
// 	}
// 	printf("NULL\n"); // Indicate the end of the queue
// }

// // Remove the last node from the queue
// void remove(POINTER node) {
// 	POINTER prevNode = node; // Keep track of the previous node
// 	while (node->next != NULL) { // Traverse to the last node
// 		prevNode = node; // Update the previous node
// 		node = node->next; // Move to the next node
// 	}	
// 	prevNode->next = NULL; // Disconnect the last node
// 	free(node); // Free memory of the last node
// }

// // Calculate the size of the queue
// int queueSize(POINTER node) {
// 	int count = 0; // Initialize a counter
// 	while (node != NULL) { // Traverse the queue
// 		count++; // Increment the counter
// 		node = node->next; // Move to the next node
// 	}	
// 	return count; // Return the size of the queue
// }

// int main() {
// 	POINTER queue = newNode(5); // Initialize the queue with one element
// 	queue = insert(8, queue); // Insert new elements into the queue
// 	queue = insert(1, queue);
// 	queue = insert(3, queue);
// 	queue = insert(5, queue);
// 	queue = insert(4, queue);
// 	queue = insert(2, queue);

// 	showQueue(queue); // Show the current state of the queue
// 	remove(queue); // Remove the last element
// 	showQueue(queue); // Show the queue again
// 	remove(queue); // Remove another element
// 	showQueue(queue); // Show the queue again

// 	printf("Size of the queue: %d\n", queueSize(queue)); // Display the size of the queue
// 	return 0;
// }
