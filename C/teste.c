/******************************************************************************
     arvoreBinaria.c
  Este programa gerencia arvores Binarias.
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef enum{esquerdo, direito} LADO;

//typedef int bool;
typedef char TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;

/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja
   encontrada.                                                                */
PONT buscarChave(TIPOCHAVE ch, PONT raiz){
  if (raiz == NULL) return NULL;
  if (raiz->chave == ch) return raiz;
  PONT aux = buscarChave(ch,raiz->esq);
  if (aux) return aux;
  return buscarChave(ch,raiz->dir);
}  

PONT criarNovoNo(TIPOCHAVE ch){
   PONT novoNo = (PONT)malloc(sizeof(NO));
   novoNo->esq = NULL;
   novoNo->dir = NULL;
   novoNo->chave = ch;
   return novoNo;
}

bool inserirFilho(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai, LADO lado){
  PONT pai = buscarChave(chavePai,raiz);
  if (!pai) return false;
  PONT novo = criarNovoNo(novaChave);
  if (lado == esquerdo){
    novo->esq = pai->esq;
    pai->esq = novo;
  }else{
     novo->esq = pai->dir;
     pai->dir = novo;              
  }
  return true;
}

void exibirArvorePreOrdem(PONT raiz){
  if (raiz == NULL) return;
  printf("%c ",raiz->chave);
  exibirArvorePreOrdem(raiz->esq);
  exibirArvorePreOrdem(raiz->dir);
}
void exibirArvoreEmOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvoreEmOrdem(raiz->esq);
  printf("%c ",raiz->chave);
  exibirArvoreEmOrdem(raiz->dir);
}
void exibirArvorePosOrdem(PONT raiz){
  if (raiz == NULL) return;
  exibirArvorePosOrdem(raiz->esq);
  exibirArvorePosOrdem(raiz->dir);
  printf("%c ",raiz->chave);
}

void exibirArvore(PONT raiz){
  if (raiz == NULL) return;
  printf("%c",raiz->chave);
  printf("(");     
  exibirArvore(raiz->esq);
  exibirArvore(raiz->dir);
  printf(")");     
}

int max(int a, int b){
  if (a>b) return a;
  return b;
}

int alturaArvore(PONT raiz){
  if (!raiz ) return 0;
  return 1 + max(alturaArvore(raiz->esq),alturaArvore(raiz->dir));
}

int numeroNos(PONT raiz){
  if (!raiz ) return 0;
  return 1 + numeroNos(raiz->esq) + numeroNos(raiz->dir);
}

void inicializar(PONT * raiz){
  *raiz = NULL;
}

void criarRaiz(PONT * raiz, TIPOCHAVE novaChave){
    *raiz = criarNovoNo(novaChave);
} 
  
int main(){
  PONT raiz;
  inicializar(&raiz);
  criarRaiz(&raiz,'D');
  inserirFilho(raiz,'B','D',esquerdo);
  inserirFilho(raiz,'E','D',direito);
  //printf("Numero de Nos: %d.\n", numeroNos(raiz));
  ///printf("Altura: %d.\n", alturaArvore(raiz));
  inserirFilho(raiz,'A','B',esquerdo);
  inserirFilho(raiz,'C','B',direito);
  inserirFilho(raiz,'G','E',direito);
  inserirFilho(raiz,'F','G',esquerdo);
  //printf("Numero de Nos: %d.\n", numeroNos(raiz));
  //printf("Altura: %d.\n", alturaArvore(raiz));
  //inserirFilho(raiz,'h','d',direito);
  //inserirFilho(raiz,'i','h',esquerdo);
  //inserirFilho(raiz,'j','i',esquerdo);
  //printf("Numero de Nos: %d.\n", numeroNos(raiz));
  //printf("Altura: %d.\n", alturaArvore(raiz));
  
  //exibirArvore(raiz);
  printf("\nPre: ");
  exibirArvorePreOrdem(raiz);
  printf("\nEm: ");
  exibirArvoreEmOrdem(raiz);
  printf("\nPos: ");
  exibirArvorePosOrdem(raiz);

  char fim;
  printf("\n\nPressione <ENTER> para terminar.\n");
  scanf("%c",&fim);

  return 0;
}
  