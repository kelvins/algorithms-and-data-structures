/*
*
*	Lista Ligada com Nó Cabeça, Circular e Ordenada (Implementação Dinâmica)
*
*/

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE; // Tipo de ID de cada nó da lista

// Estrutura de dados que representa cada nó da lista
typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX* prox;
}NO, *PONT;

typedef struct{
	PONT cab; // Nó cabeça
}LISTA;

void inicializar(LISTA *L){
	// Nó cabeça não deixa a lista ficar vazia, também pode ser usado como sentinela
	L->cab = (PONT) malloc( sizeof(NO) );
	L->cab->prox = L->cab; // Começa apontando para o próprio nó, pois é circular
}

// Como neste método não irá alterar a lista, pode ser passado uma cópia dela e não necessáriamente um ponteiro para ela
PONT buscaSequencial(TIPOCHAVE ch, LISTA L, PONT* ant){
	*ant = L.cab; // Sendo uma cópia pode-se usar o ponto (.) no lugar de seta (->), o ant guarda o ponteiro para o nó encontrado
	PONT pos = L.cab->prox;
	L.cab->chave = ch; // Grava o valor no nó cabeça para ser utilizado como sentinela, será o último a ser comparado
	while(pos->chave != ch){ 
		*ant = pos; // Guarda o ponteiro para o nó
		pos = pos->prox; // Vai para o próximo nó
	}
	if( pos != L.cab ) // Se o nó não é o nó cabeça é pq encontrou
		return pos; // Retorna o nó
	else
		return NULL; // Senão não encontrou retorna NULL
}

bool excluir(TIPOCHAVE ch, LISTA *L){
	PONT aux, ant;
	aux = buscaSequencial(ch, *L, &ant); // Busca o valor para excluir, o ant é passado como endereço de memória, assim a função busca altera ele, guardando o valor anterior
	if( aux == NULL ) return false; // Não encontrou
	ant->prox = aux->prox; // Nó anterior aponta para o próximo, no caso o próximo que o nó a ser excluído está apontando
	free(aux); // Libera a memória
	return true;
}

void inserir(TIPOCHAVE ch, LISTA *L){
	PONT ant = L->cab; // O ant guarda o ponteiro para o nó anterior
	PONT pos = L->cab->prox; // O pos guarda o ponteiro para o atual

	while(pos->chave < ch && pos != L->cab){
		ant = pos; // Guarda o ponteiro para o nó atual, que será o anterior
		pos = pos->prox; // Vai para o próximo nó
	}
	// Quando encontrou a posição correta na ordem crescente
	PONT novo_no = (PONT) malloc( sizeof(NO) ); // Cria um novo nó
	novo_no->chave = ch; // Coloca a chave no nó
	novo_no->prox  = pos; // Aponta para o próximo nó
	ant->prox = novo_no; // Nó anterior aponta para o novo nó
}

PONT mostrarLista(LISTA L){
	PONT pos = L.cab->prox; // Pos recebe o primeiro elemento depois do nó cabeça
	while(pos != L.cab){ // Se não for o nó cabeça, a lista não está vazia
		printf("[ %d ]->", pos->chave); // Mostra o valor do nó
		pos = pos->prox; // Vai para o próximo nó
	}printf("\n");
}

int main(){
	
	LISTA lista;
	inicializar(&lista);

	inserir(4, &lista);
	inserir(6, &lista);
	inserir(2, &lista);
	inserir(3, &lista);
	inserir(1, &lista);
	inserir(5, &lista);

	mostrarLista(lista);

	excluir(2, &lista);
	excluir(4, &lista);
	excluir(6, &lista);

	mostrarLista(lista);

	// Exemplo de busca na lista
	PONT aux;
	int valor = 2;
	if( buscaSequencial(valor, lista, &aux) != NULL )
		printf("Valor %d encontrado.\n", valor );
	else
		printf("Valor %d não encontrado.\n", valor);

	return 0;
}



//  In english

/*
*
*	Circular Ordered Linked List with Head Node (Dynamic Implementation)
*
*/


// typedef int KeyType; // Type of ID for each node in the list

// // Data structure representing each node in the list
// typedef struct Node {
// 	KeyType key;
// 	struct Node* next;
// } Node, *Pointer;

// typedef struct {
// 	Pointer head; // Head node
// } List;

// void initialize(List *list) {
// 	// Head node prevents the list from being empty and can also be used as a sentinel
// 	list->head = (Pointer) malloc(sizeof(Node));
// 	list->head->next = list->head; // Initially points to itself since it is circular
// }

// // This method does not alter the list, so a copy can be passed instead of a pointer
// Pointer sequential_search(KeyType key, List list, Pointer* previous) {
// 	*previous = list.head; // As it's a copy, dot (.) can be used instead of arrow (->), previous holds the pointer to the found node
// 	Pointer current = list.head->next;
// 	list.head->key = key; // Store the value in the head node to be used as a sentinel, it will be the last to be compared
// 	while (current->key != key) {
// 		*previous = current; // Store the pointer to the node
// 		current = current->next; // Move to the next node
// 	}
// 	if (current != list.head) // If the node is not the head node, it means it was found
// 		return current; // Return the node
// 	else
// 		return NULL; // If not found, return NULL
// }

// bool delete_node(KeyType key, List *list) {
// 	Pointer current, previous;
// 	current = sequential_search(key, *list, &previous); // Search for the value to delete, previous is passed as an address, so the search function alters it
// 	if (current == NULL) return false; // Not found
// 	previous->next = current->next; // Previous node points to the next node (the one the node to be deleted points to)
// 	free(current); // Free the memory
// 	return true;
// }

// void insert(KeyType key, List *list) {
// 	Pointer previous = list->head; // previous holds the pointer to the previous node
// 	Pointer current = list->head->next; // current holds the pointer to the current node

// 	while (current->key < key && current != list->head) {
// 		previous = current; // Store the pointer to the current node, which will be the previous
// 		current = current->next; // Move to the next node
// 	}
// 	// When the correct position is found in ascending order
// 	Pointer new_node = (Pointer) malloc(sizeof(Node)); // Create a new node
// 	new_node->key = key; // Assign the key to the node
// 	new_node->next = current; // Point to the next node
// 	previous->next = new_node; // Previous node points to the new node
// }

// Pointer display_list(List list) {
// 	Pointer current = list.head->next; // current receives the first element after the head node
// 	while (current != list.head) { // If it's not the head node, the list is not empty
// 		printf("[ %d ]->", current->key); // Display the value of the node
// 		current = current->next; // Move to the next node
// 	}
// 	printf("\n");
// }

// int main() {
// 	List list;
// 	initialize(&list);

// 	insert(4, &list);
// 	insert(6, &list);
// 	insert(2, &list);
// 	insert(3, &list);
// 	insert(1, &list);
// 	insert(5, &list);

// 	display_list(list);

// 	delete_node(2, &list);
// 	delete_node(4, &list);
// 	delete_node(6, &list);

// 	display_list(list);

// 	// Example of searching the list
// 	Pointer found_node;
// 	int search_value = 2;
// 	if (sequential_search(search_value, list, &found_node) != NULL)
// 		printf("Value %d found.\n", search_value);
// 	else
// 		printf("Value %d not found.\n", search_value);

// 	return 0;
// }
