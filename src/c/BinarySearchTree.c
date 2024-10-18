/*
*	Árvore Binária de Busca em C
*
*		 ( 6 )
*	     /   \
*	 ( 2 )   ( 7 )
* 	 /   \		\
*( 1 )   ( 4 )	( 8 )
*		 /   \
*	 ( 3 )	 ( 5 )
*/

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX *esq, *dir;
}NO, *PONT; // NO é a estrutura e PONT é um ponteiro de NO

int max(int a, int b){
	if( a > b )
		return a;
	return b;
}

int altura(PONT no){
	if( no == NULL ) // Mesma coisa que usar if(!no)
		return 0;
	return 1 + max( altura(no->esq), altura(no->dir) ); // Percorre a arvore pela esquerda e pela direita para ver qual tem altura maior
}

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
	if( !raiz )
		return NULL;
	if( raiz->chave == ch )
		return raiz;
	if( raiz->chave < ch )
		buscaBinaria(ch, raiz->dir);
	else
		buscaBinaria(ch, raiz->esq);
}

PONT buscaBinariaLinear(TIPOCHAVE ch, PONT atual){
	while( atual != NULL ){
		if( atual->chave == ch )
			return atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return NULL;
}

PONT criaNo(TIPOCHAVE ch){
	PONT no = (PONT) malloc( sizeof(NO) );
	no->esq = NULL;
	no->dir = NULL;
	no->chave = ch;
	return no;
}

bool inserir(TIPOCHAVE ch, PONT atual){
	PONT ant;
	// Percorre a arvore para a direita ou esquerda até encontrar uma posição NULL (vazia)
	while(atual != NULL){
		ant = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	atual = criaNo(ch); // Utiliza a váriavel atual, pois estava 'sobrando'
	if( ant->chave < ch )
		ant->dir = atual;
	else
		ant->esq = atual;
	return true;
}

PONT buscaNoPai(TIPOCHAVE ch, PONT atual){
	PONT noPai = atual;
	while( atual != NULL ){
		if( atual->chave == ch )
			return noPai;
		noPai = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return noPai;
}

PONT maiorAesquerda(PONT atual){
	atual = atual->esq;
	while( atual->dir != NULL )
		atual = atual->dir;
	return atual;
}

bool excluir(TIPOCHAVE ch, PONT raiz){
	PONT atual, noPai, substituto, paiSubstituto;
	substituto = NULL;
	atual = buscaBinaria(ch, raiz);
	if( atual == NULL ) return false; // Não encontrou a chave
	noPai = buscaNoPai(ch, raiz);
	if( atual->esq == NULL || atual->dir == NULL ){ // Se tem 0 ou 1 filho
		if( atual->esq == NULL )
			substituto = atual->dir;
		else
			substituto = atual->esq;
		if( noPai == NULL ){ // Único que não tem pai é a raiz
			raiz = substituto;
		}else{
			if( ch < noPai->chave)
				noPai->esq = substituto;
			else
				noPai->dir = substituto;
		}
		free(atual);
	}else{
		substituto = maiorAesquerda(atual);
		atual->chave = substituto->chave;
		if( substituto->esq != NULL )
			atual->esq = substituto->esq;
		else
			atual->esq = NULL;
		free(substituto);
	}
	return true;
}

void preordem(PONT no){ // R - E - D
	if( !no ) return;
	printf("%d, ", no->chave);
	preordem(no->esq);
	preordem(no->dir);
}

void posordem(PONT no){ // E - D - R
	if( !no ) return;
	posordem(no->esq);
	posordem(no->dir);
	printf("%d, ", no->chave);
}

void emordem(PONT no){ // E - R - D
	if( !no ) return;
	emordem(no->esq);
	printf("%d, ", no->chave);
	emordem(no->dir);
}

// Esta função não está funcionando
bool insereRecursivo(TIPOCHAVE ch, PONT no){
	PONT ant;
	if( !no ){
		no = criaNo(ch);
	}else{
		ant = no;
		if( ch < no->chave )
			insereRecursivo(ch, no->esq);
		else
			insereRecursivo(ch, no->dir);
	}
	if( ant->chave < ch )
		ant->dir = no;
	else
		ant->esq = no;
	return true;
}

int main(){
	PONT noArvore = criaNo(6);

	inserir(2, noArvore);
	inserir(1, noArvore);
	inserir(4, noArvore);
	inserir(7, noArvore);
	inserir(8, noArvore);
	inserir(3, noArvore);
	inserir(5, noArvore);

	int valorBuscado = 7;
	if( buscaBinaria(valorBuscado, noArvore) )
		printf("Busca : %d\n", buscaBinaria(valorBuscado, noArvore)->chave );
	else
		printf("Não encontrou\n");

	excluir(4, noArvore);

	printf("Pre-ordem: ");
	preordem(noArvore);
	printf("\n");
	printf("Em-ordem: ");
	emordem(noArvore);
	printf("\n");
	printf("Pos-ordem: ");
	posordem(noArvore);

	printf("\nAltura: %d\n", altura(noArvore) );
	return 0;
}








// IN english 
/*
*	Binary Search Tree in C
*
*		 ( 6 )
*	     /   \
*	 ( 2 )   ( 7 )
* 	 /   \		\
*	( 1 )   ( 4 )	( 8 )
*		 /   \
*	 ( 3 )	 ( 5 )
*/
// typedef int KEYTYPE;

// typedef struct AUX{
// 	KEYTYPE key;
// 	struct AUX *left, *right;
// }NODE, *PTR; // NODE is the structure, and PTR is a pointer to NODE

// int max(int a, int b){
// 	if( a > b )
// 		return a;
// 	return b;
// }

// int height(PTR node){
// 	if( node == NULL ) // Same as using if(!node)
// 		return 0;
// 	return 1 + max( height(node->left), height(node->right) ); // Traverses the tree from left and right to check which one has a greater height
// }

// PTR binarySearch(KEYTYPE key, PTR root){
// 	if( !root )
// 		return NULL;
// 	if( root->key == key )
// 		return root;
// 	if( root->key < key )
// 		binarySearch(key, root->right);
// 	else
// 		binarySearch(key, root->left);
// }

// PTR linearBinarySearch(KEYTYPE key, PTR current){
// 	while( current != NULL ){
// 		if( current->key == key )
// 			return current;
// 		if( current->key < key )
// 			current = current->right;
// 		else
// 			current = current->left;
// 	}
// 	return NULL;
// }

// PTR createNode(KEYTYPE key){
// 	PTR node = (PTR) malloc( sizeof(NODE) );
// 	node->left = NULL;
// 	node->right = NULL;
// 	node->key = key;
// 	return node;
// }

// bool insert(KEYTYPE key, PTR current){
// 	PTR previous;
// 	// Traverses the tree to the right or left until it finds a NULL (empty) position
// 	while(current != NULL){
// 		previous = current;
// 		if( current->key < key )
// 			current = current->right;
// 		else
// 			current = current->left;
// 	}
// 	current = createNode(key); // Uses the current variable, as it was "leftover"
// 	if( previous->key < key )
// 		previous->right = current;
// 	else
// 		previous->left = current;
// 	return true;
// }

// PTR searchParent(KEYTYPE key, PTR current){
// 	PTR parent = current;
// 	while( current != NULL ){
// 		if( current->key == key )
// 			return parent;
// 		parent = current;
// 		if( current->key < key )
// 			current = current->right;
// 		else
// 			current = current->left;
// 	}
// 	return parent;
// }

// PTR largestOnLeft(PTR current){
// 	current = current->left;
// 	while( current->right != NULL )
// 		current = current->right;
// 	return current;
// }

// bool deleteNode(KEYTYPE key, PTR root){
// 	PTR current, parent, substitute, parentSubstitute;
// 	substitute = NULL;
// 	current = binarySearch(key, root);
// 	if( current == NULL ) return false; // Did not find the key
// 	parent = searchParent(key, root);
// 	if( current->left == NULL || current->right == NULL ){ // If it has 0 or 1 child
// 		if( current->left == NULL )
// 			substitute = current->right;
// 		else
// 			substitute = current->left;
// 		if( parent == NULL ){ // The only one without a parent is the root
// 			root = substitute;
// 		}else{
// 			if( key < parent->key)
// 				parent->left = substitute;
// 			else
// 				parent->right = substitute;
// 		}
// 		free(current);
// 	}else{
// 		substitute = largestOnLeft(current);
// 		current->key = substitute->key;
// 		if( substitute->left != NULL )
// 			current->left = substitute->left;
// 		else
// 			current->left = NULL;
// 		free(substitute);
// 	}
// 	return true;
// }

// void preOrder(PTR node){ // Root - Left - Right
// 	if( !node ) return;
// 	printf("%d, ", node->key);
// 	preOrder(node->left);
// 	preOrder(node->right);
// }

// void postOrder(PTR node){ // Left - Right - Root
// 	if( !node ) return;
// 	postOrder(node->left);
// 	postOrder(node->right);
// 	printf("%d, ", node->key);
// }

// void inOrder(PTR node){ // Left - Root - Right
// 	if( !node ) return;
// 	inOrder(node->left);
// 	printf("%d, ", node->key);
// 	inOrder(node->right);
// }

// // This function is not working
// bool recursiveInsert(KEYTYPE key, PTR node){
// 	PTR previous;
// 	if( !node ){
// 		node = createNode(key);
// 	}else{
// 		previous = node;
// 		if( key < node->key )
// 			recursiveInsert(key, node->left);
// 		else
// 			recursiveInsert(key, node->right);
// 	}
// 	if( previous->key < key )
// 		previous->right = node;
// 	else
// 		previous->left = node;
// 	return true;
// }

// int main(){
// 	PTR treeRoot = createNode(6);

// 	insert(2, treeRoot);
// 	insert(1, treeRoot);
// 	insert(4, treeRoot);
// 	insert(7, treeRoot);
// 	insert(8, treeRoot);
// 	insert(3, treeRoot);
// 	insert(5, treeRoot);

// 	int searchedValue = 7;
// 	if( binarySearch(searchedValue, treeRoot) )
// 		printf("Search: %d\n", binarySearch(searchedValue, treeRoot)->key );
// 	else
// 		printf("Not found\n");

// 	deleteNode(4, treeRoot);

// 	printf("Pre-order: ");
// 	preOrder(treeRoot);
// 	printf("\n");
// 	printf("In-order: ");
// 	inOrder(treeRoot);
// 	printf("\n");
// 	printf("Post-order: ");
// 	postOrder(treeRoot);

// 	printf("\nHeight: %d\n", height(treeRoot) );
// 	return 0;
// }
