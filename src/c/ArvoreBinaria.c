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