#include <stdio.h>
#include <stdlib.h>

// Essa é uma árvore binária não balanceada.

struct No {

    int valor;
    struct No* esquerda;
    struct No* direita;
    int altura;
};

int altura(struct No *n){

    if(n == NULL)
        return 0;
    return n->altura;
}

int max(int a, int b){
    return (a > b)? a : b;
}

struct No* novoNo(int valor){

    struct No* novoNo = (struct No*)malloc(sizeof(struct No));

    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    
    return novoNo;
}

struct No* inserir(struct No* raiz, int valor){

    if(raiz == NULL){
        return novoNo(valor);
    }
    if(valor <= raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } 
    else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

    return raiz;
}

int busca(struct No* raiz, int valor){
    
    if(raiz == NULL){
        printf(" Valor [%d] não encontrado.\n", valor);
    }
    else if(raiz->valor == valor){
        printf(" Valor [%d] encontrado.\n", valor);
    }
    else if(valor <= raiz->valor){
        return busca(raiz->esquerda, valor);
    }
    else if(valor >= raiz->valor){
        return busca(raiz->direita, valor);
    }
}

void preorder(struct No* raiz){

    if(raiz == NULL) return;
    printf("[%d]", raiz->valor);
    preorder(raiz->esquerda);
    preorder(raiz->direita);
}

void inorder(struct No* raiz){

    if(raiz == NULL) return;
    inorder(raiz->esquerda);
    printf("[%d]", raiz->valor);
    inorder(raiz->direita);
}

void postorder(struct No* raiz){
    
    if(raiz == NULL) return;
    postorder(raiz->esquerda);
    postorder(raiz->direita);
    printf("[%d]", raiz->valor);
}

void levelOrder(struct No* raiz, int level){

    if(raiz == NULL){
        return;
    }
    if(level == 0){
        printf("[%d]", raiz->valor);
    } 
    else{ 
        levelOrder(raiz->esquerda, level-1);
        levelOrder(raiz->direita, level-1);
    }
}

void printLevelOrder(struct No* raiz){
    int h = altura(raiz);
    for(int i = 0; i < h; i++){
        levelOrder(raiz, i);
    }
}

struct No* encontraMenor(struct No* raiz){
    struct No* atual = raiz;
    while(atual->esquerda != NULL){
        atual = atual->esquerda;
    }
    return atual;
}


struct No* deleta(struct No* raiz, int valor){

    if(raiz == NULL){
        return raiz;
    }
    if(valor < raiz->valor) {
        raiz->esquerda = deleta(raiz->esquerda, valor);
    } 
    else if(valor > raiz->valor){
        raiz->direita = deleta(raiz->direita, valor);
    }
    else{
        if( (raiz->esquerda == NULL) || (raiz->direita == NULL) ){
            struct No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            
            if(temp == NULL){
                temp = raiz;
                raiz = NULL;
            } else{
                *raiz = *temp;
                free(temp);
            }
        }
        else{
            struct No* temp = encontraMenor(raiz->direita);
            raiz->valor = temp->valor;
            raiz->direita = deleta(raiz->direita, temp->valor);
        }
    }

    if(raiz == NULL){
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    
    return raiz;
}


int main(void){

    struct No* raiz;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 33);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 57);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 12);

    busca(raiz, 33);
    busca(raiz, 23);

    printf("\n Preorder: ");
    preorder(raiz);

    printf("\n Inorder: ");
    inorder(raiz);

    printf("\n Postorder: ");
    postorder(raiz);

    printf("\n Levelorder: ");
    printLevelOrder(raiz);

    raiz = deleta(raiz, 7);

    printf("\n Levelorder: ");
    printLevelOrder(raiz);

    raiz = deleta(raiz, 6);

    printf("\n Levelorder: ");
    printLevelOrder(raiz);

    return 0;

}





//  In english 

// This is an unbalanced binary tree.

struct Node {

    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node *n){

    if(n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

struct Node* newNode(int value){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    
    return newNode;
}

struct Node* insert(struct Node* root, int value){

    if(root == NULL){
        return newNode(value);
    }
    if(value <= root->value) {
        root->left = insert(root->left, value);
    } 
    else {
        root->right = insert(root->right, value);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

int search(struct Node* root, int value){
    
    if(root == NULL){
        printf(" Value [%d] not found.\n", value);
    }
    else if(root->value == value){
        printf(" Value [%d] found.\n", value);
    }
    else if(value <= root->value){
        return search(root->left, value);
    }
    else if(value >= root->value){
        return search(root->right, value);
    }
}

void preorder(struct Node* root){

    if(root == NULL) return;
    printf("[%d]", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){

    if(root == NULL) return;
    inorder(root->left);
    printf("[%d]", root->value);
    inorder(root->right);
}

void postorder(struct Node* root){
    
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("[%d]", root->value);
}

void levelOrder(struct Node* root, int level){

    if(root == NULL){
        return;
    }
    if(level == 0){
        printf("[%d]", root->value);
    } 
    else{ 
        levelOrder(root->left, level-1);
        levelOrder(root->right, level-1);
    }
}

void printLevelOrder(struct Node* root){
    int h = height(root);
    for(int i = 0; i < h; i++){
        levelOrder(root, i);
    }
}

struct Node* findMin(struct Node* root){
    struct Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct Node* deleteNode(struct Node* root, int value){

    if(root == NULL){
        return root;
    }
    if(value < root->value) {
        root->left = deleteNode(root->left, value);
    } 
    else if(value > root->value){
        root->right = deleteNode(root->right, value);
    }
    else{
        if( (root->left == NULL) || (root->right == NULL) ){
            struct Node* temp = root->left ? root->left : root->right;
            
            if(temp == NULL){
                temp = root;
                root = NULL;
            } else{
                *root = *temp;
                free(temp);
            }
        }
        else{
            struct Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    
    return root;
}


// int main(void){

//     struct Node* root;
//     root = insert(root, 10);
//     root = insert(root, 2);
//     root = insert(root, 33);
//     root = insert(root, 4);
//     root = insert(root, 57);
//     root = insert(root, 6);
//     root = insert(root, 12);

//     search(root, 33);
//     search(root, 23);

//     printf("\n Preorder: ");
//     preorder(root);

//     printf("\n Inorder: ");
//     inorder(root);

//     printf("\n Postorder: ");
//     postorder(root);

//     printf("\n Levelorder: ");
//     printLevelOrder(root);

//     root = deleteNode(root, 7);

//     printf("\n Levelorder: ");
//     printLevelOrder(root);

//     root = deleteNode(root, 6);

//     printf("\n Levelorder: ");
//     printLevelOrder(root);

//     return 0;

// }
