/*
 *	Binary Search Tree in C
 *
 *		 ( 6 )
 *	     /   \
 *	 ( 2 )   ( 7 )
 * 	 /   \		\
 *( 1 )   ( 4 )	( 8 )
 *		 /   \
 *	 ( 3 )	 ( 5 )
 */

#include <malloc.h>
#include <stdio.h>

typedef int TIPOCHAVE;

typedef struct AUX {
  TIPOCHAVE chave;
  struct AUX *esq, *dir;
} NO, *PONT; // NO is the structure and PONT is a pointer to NO

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int altura(PONT no) {
  if (no == NULL) // Mesma coisa que usar if(!no)
    return 0;
  return 1 +
         max(altura(no->esq),
             altura(no->dir)); // Percorre a arvore pela esquerda e pela
                               // right side to check which subtree is taller
}

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz) {
  if (!raiz)
    return NULL;
  if (raiz->chave == ch)
    return raiz;
  if (raiz->chave < ch)
    buscaBinaria(ch, raiz->dir);
  else
    buscaBinaria(ch, raiz->esq);
}

PONT buscaBinariaLinear(TIPOCHAVE ch, PONT atual) {
  while (atual != NULL) {
    if (atual->chave == ch)
      return atual;
    if (atual->chave < ch)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return NULL;
}

PONT criaNo(TIPOCHAVE ch) {
  PONT no = (PONT)malloc(sizeof(NO));
  no->esq = NULL;
  no->dir = NULL;
  no->chave = ch;
  return no;
}

bool inserir(TIPOCHAVE ch, PONT atual) {
  PONT ant;
  // Traverse right or left until a NULL position is found
  // (empty)
  while (atual != NULL) {
    ant = atual;
    if (atual->chave < ch)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  atual = criaNo(ch); // Reuse the current variable, which was available
  if (ant->chave < ch)
    ant->dir = atual;
  else
    ant->esq = atual;
  return true;
}

PONT buscaNoPai(TIPOCHAVE ch, PONT atual) {
  PONT noPai = atual;
  while (atual != NULL) {
    if (atual->chave == ch)
      return noPai;
    noPai = atual;
    if (atual->chave < ch)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return noPai;
}

PONT maiorAesquerda(PONT atual) {
  atual = atual->esq;
  while (atual->dir != NULL)
    atual = atual->dir;
  return atual;
}

bool excluir(TIPOCHAVE ch, PONT raiz) {
  PONT atual, noPai, substituto, paiSubstituto;
  substituto = NULL;
  atual = buscaBinaria(ch, raiz);
  if (atual == NULL)
    return false; // The key was not found
  noPai = buscaNoPai(ch, raiz);
  if (atual->esq == NULL || atual->dir == NULL) { // Se tem 0 ou 1 filho
    if (atual->esq == NULL)
      substituto = atual->dir;
    else
      substituto = atual->esq;
    if (noPai == NULL) { // The root is the only node without a parent
      raiz = substituto;
    } else {
      if (ch < noPai->chave)
        noPai->esq = substituto;
      else
        noPai->dir = substituto;
    }
    free(atual);
  } else {
    substituto = maiorAesquerda(atual);
    atual->chave = substituto->chave;
    if (substituto->esq != NULL)
      atual->esq = substituto->esq;
    else
      atual->esq = NULL;
    free(substituto);
  }
  return true;
}

void preordem(PONT no) { // R - E - D
  if (!no)
    return;
  printf("%d, ", no->chave);
  preordem(no->esq);
  preordem(no->dir);
}

void posordem(PONT no) { // E - D - R
  if (!no)
    return;
  posordem(no->esq);
  posordem(no->dir);
  printf("%d, ", no->chave);
}

void emordem(PONT no) { // E - R - D
  if (!no)
    return;
  emordem(no->esq);
  printf("%d, ", no->chave);
  emordem(no->dir);
}

// This function is not working
bool insereRecursivo(TIPOCHAVE ch, PONT no) {
  PONT ant;
  if (!no) {
    no = criaNo(ch);
  } else {
    ant = no;
    if (ch < no->chave)
      insereRecursivo(ch, no->esq);
    else
      insereRecursivo(ch, no->dir);
  }
  if (ant->chave < ch)
    ant->dir = no;
  else
    ant->esq = no;
  return true;
}

int main() {
  PONT noArvore = criaNo(6);

  inserir(2, noArvore);
  inserir(1, noArvore);
  inserir(4, noArvore);
  inserir(7, noArvore);
  inserir(8, noArvore);
  inserir(3, noArvore);
  inserir(5, noArvore);

  int valorBuscado = 7;
  if (buscaBinaria(valorBuscado, noArvore))
    printf("Busca : %d\n", buscaBinaria(valorBuscado, noArvore)->chave);
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

  printf("\nAltura: %d\n", altura(noArvore));
  return 0;
}