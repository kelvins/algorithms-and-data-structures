/*
*	Pilha Dinâmica utilizando uma Lista Ligada em C
*/

#include <stdio.h>
#include <malloc.h>

#define ERRO -1

typedef int TIPOCHAVE;

typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX *prox;
}*PILHA;

PILHA CREATE(TIPOCHAVE ch){
	PILHA novaPilha = (PILHA) malloc( sizeof(PILHA) );
	novaPilha->chave = ch;
	novaPilha->prox = NULL;
	return novaPilha;
}

PILHA PUSH(TIPOCHAVE ch, PILHA pi){
	/*while( pi->prox != NULL ){
		pi = pi->prox;
	}*/
	PILHA novo = CREATE(ch);
	//pi->prox = novo;
	novo->prox = pi;
	return novo;
}

PILHA POP(PILHA pi){
	PILHA sub = pi->prox;
	free(pi);
	return sub;
}

void SHOW(PILHA pi){
	printf("PILHA:\n");
	while( pi->prox != NULL ){
		printf("[ %d ]\n", pi->chave);
		pi = pi->prox;
	}
	printf("[ %d ]\n", pi->chave);
}

bool SEARCH(TIPOCHAVE ch, PILHA pi){
	bool vAchou = false;
	while(pi != NULL){
		if( pi->chave == ch )
			vAchou = true;
		pi = pi->prox;
	}
	return vAchou;
}

int main(){
	PILHA vPilha; 
	
	vPilha = PUSH(1, vPilha);
	vPilha = PUSH(2, vPilha);
	vPilha = PUSH(3, vPilha);
	vPilha = PUSH(4, vPilha);
	vPilha = PUSH(5, vPilha);
	vPilha = PUSH(6, vPilha);

	SHOW(vPilha);
	
	vPilha = POP(vPilha);
	vPilha = POP(vPilha);

	SHOW(vPilha);

	if( SEARCH(6, vPilha) )
		printf("\nAchou\n");
	else
		printf("\nNão achou\n");

	return 0;
}





/*
* Dynamic Stack using a Linked List in C
*/


// #define ERROR -1 // Define a constant for error handling

// typedef int KEYTYPE; // Define KEYTYPE as an integer

// typedef struct NODE {
// 	KEYTYPE key; // The key/value of the node
// 	struct NODE *next; // Pointer to the next node
// }*STACK; // Define STACK as a pointer to a NODE

// // Create a new stack with a given key
// STACK CREATE(KEYTYPE ch) {
// 	STACK newStack = (STACK) malloc(sizeof(STACK)); // Allocate memory for a new stack node
// 	newStack->key = ch; // Set the key of the new node
// 	newStack->next = NULL; // Initialize the next pointer to NULL
// 	return newStack; // Return the new stack node
// }

// // Push a new key onto the stack
// STACK PUSH(KEYTYPE ch, STACK pi) {
// 	STACK new = CREATE(ch); // Create a new node
// 	new->next = pi; // Set the next pointer of the new node to the current top of the stack
// 	return new; // Return the new top of the stack
// }

// // Pop the top element from the stack
// STACK POP(STACK pi) {
// 	STACK sub = pi->next; // Get the next element
// 	free(pi); // Free the memory of the top node
// 	return sub; // Return the new top of the stack
// }

// // Show the elements in the stack
// void SHOW(STACK pi) {
// 	printf("STACK:\n");
// 	while (pi->next != NULL) { // Traverse until the second-to-last element
// 		printf("[ %d ]\n", pi->key); // Print the key of the current node
// 		pi = pi->next; // Move to the next node
// 	}
// 	printf("[ %d ]\n", pi->key); // Print the last element
// }

// // Search for a key in the stack
// bool SEARCH(KEYTYPE ch, STACK pi) {
// 	bool found = false; // Initialize found flag
// 	while (pi != NULL) { // Traverse the stack
// 		if (pi->key == ch) // Check if the current node's key matches
// 			found = true; // Set found flag to true
// 		pi = pi->next; // Move to the next node
// 	}
// 	return found; // Return the found status
// }

// int main() {
// 	STACK vStack; // Declare a stack pointer

// 	vStack = PUSH(1, vStack); // Push elements onto the stack
// 	vStack = PUSH(2, vStack);
// 	vStack = PUSH(3, vStack);
// 	vStack = PUSH(4, vStack);
// 	vStack = PUSH(5, vStack);
// 	vStack = PUSH(6, vStack);

// 	SHOW(vStack); // Display the stack contents
	
// 	vStack = POP(vStack); // Pop two elements from the stack
// 	vStack = POP(vStack);

// 	SHOW(vStack); // Display the stack contents again

// 	if (SEARCH(6, vStack)) // Search for a key in the stack
// 		printf("\nFound\n");
// 	else
// 		printf("\nNot found\n");

// 	return 0; // Exit the program
// }
