/*
*	Exemplo de Lista Ligada Dinâmica Não Ordenada em C
*/

#include <stdio.h>
#include <malloc.h>

#define ERRO -1

typedef int TIPOCHAVE;

typedef struct aux{
	TIPOCHAVE chave;
	struct aux *prox;
}REGISTRO, *PONT;

PONT criaRegistro(TIPOCHAVE ch){
	PONT rg = (PONT) malloc( sizeof(PONT) );
	rg->chave = ch;
	rg->prox = NULL;
	return rg;
}

PONT insereRegistro(TIPOCHAVE ch, PONT rg){
	if( rg == NULL ) 
		return criaRegistro(ch); // Se não tem nenhum registro na lista cria um novo
	while( rg->prox != NULL )
		rg = rg->prox;
	rg->prox = criaRegistro(ch);
	return NULL;
}

void mostraLista(PONT rg){
	if( rg == NULL ) return;
	printf("%d, ", rg->chave);
	mostraLista(rg->prox);
}

PONT buscaSequencial(TIPOCHAVE ch, PONT rg){
	while( rg != NULL ){
		if( rg->chave == ch )
			return rg;
		rg = rg->prox;
	}
	return NULL;
}

bool deletaRegistro(TIPOCHAVE ch, PONT rg){
	PONT ant;
	while( rg != NULL ){
		if( rg->chave == ch ){
			ant->prox = rg->prox;
			free(rg);
			return true;
		}
		ant = rg;
		rg = rg->prox;
	}
	printf("\nChave %d não encontrada.\n",ch);
	return false;	
}

int main(){
	PONT RG = insereRegistro(23, RG);
	insereRegistro(34, RG);
	insereRegistro(12, RG);
	insereRegistro(63, RG);
	insereRegistro(45, RG);

	mostraLista(RG);

	TIPOCHAVE ch = 64;
	if( buscaSequencial(ch, RG) != NULL )
		printf("\nEncontrou chave %d\n", ch);
	else
		printf("\nNão encontrou chave %d\n", ch);

	deletaRegistro(63, RG);
	mostraLista(RG);
	
	printf("\n");
	deletaRegistro(34, RG);
	mostraLista(RG);
	return 0;
}

//  In enlgish 

/*
* Example of a Dynamic Unordered Linked List in C
*/

// #include <stdio.h>
// #include <stdlib.h>  // Changed from <malloc.h> to <stdlib.h>

// #define ERROR -1

// typedef int KEY_TYPE;

// typedef struct aux {
//     KEY_TYPE key;
//     struct aux *next;
// } RECORD, *POINTER;

// POINTER createRecord(KEY_TYPE ch) {
//     POINTER rg = (POINTER) malloc(sizeof(RECORD)); // Allocating memory for a new record
//     rg->key = ch;   // Assigning the key value
//     rg->next = NULL; // Initializing the next pointer to NULL
//     return rg;
// }

// POINTER insertRecord(KEY_TYPE ch, POINTER rg) {
//     if (rg == NULL) 
//         return createRecord(ch); // If the list is empty, create a new record
//     while (rg->next != NULL)
//         rg = rg->next; // Move to the end of the list
//     rg->next = createRecord(ch); // Insert the new record at the end
//     return NULL;
// }

// void displayList(POINTER rg) {
//     if (rg == NULL) return; // Base case for recursion
//     printf("%d, ", rg->key); // Print the current key
//     displayList(rg->next); // Recursively display the next records
// }

// POINTER sequentialSearch(KEY_TYPE ch, POINTER rg) {
//     while (rg != NULL) {
//         if (rg->key == ch)
//             return rg; // Return the record if the key matches
//         rg = rg->next; // Move to the next record
//     }
//     return NULL; // Key not found
// }

// bool deleteRecord(KEY_TYPE ch, POINTER rg) {
//     POINTER prev = NULL; // Pointer to the previous record
//     while (rg != NULL) {
//         if (rg->key == ch) {
//             if (prev != NULL) {
//                 prev->next = rg->next; // Bypass the current record
//             }
//             free(rg); // Free memory of the deleted record
//             return true; // Return success
//         }
//         prev = rg; // Move prev to current
//         rg = rg->next; // Move to the next record
//     }
//     printf("\nKey %d not found.\n", ch);
//     return false;    
// }

// int main() {
//     POINTER RG = NULL; // Initialize the head of the list as NULL
//     RG = insertRecord(23, RG); // Insert records into the list
//     insertRecord(34, RG);
//     insertRecord(12, RG);
//     insertRecord(63, RG);
//     insertRecord(45, RG);

//     displayList(RG); // Display the list

//     KEY_TYPE ch = 64;
//     if (sequentialSearch(ch, RG) != NULL)
//         printf("\nFound key %d\n", ch);
//     else
//         printf("\nKey %d not found\n", ch);

//     deleteRecord(63, RG); // Delete a record
//     displayList(RG); // Display the list again
    
//     printf("\n");
//     deleteRecord(34, RG); // Delete another record
//     displayList(RG); // Display the list again
//     return 0;
// }
