/*
 *	Dynamic Stack using a Linked List in C
 */

#include <malloc.h>
#include <stdio.h>

#define ERRO -1

typedef int KEY_TYPE;

typedef struct EdgeNode {
  KEY_TYPE key;
  struct EdgeNode *prox;
} *Stack;

Stack CREATE(KEY_TYPE key) {
  Stack newStack = (Stack)malloc(sizeof(Stack));
  newStack->key = key;
  newStack->prox = NULL;
  return newStack;
}

Stack PUSH(KEY_TYPE key, Stack pi) {
  /*while( pi->prox != NULL ){
          pi = pi->prox;
  }*/
  Stack newNode = CREATE(key);
  // pi->prox = novo;
  newNode->prox = pi;
  return newNode;
}

Stack POP(Stack pi) {
  Stack rest = pi->prox;
  free(pi);
  return rest;
}

void SHOW(Stack pi) {
  printf("STACK:\n");
  while (pi->prox != NULL) {
    printf("[ %d ]\n", pi->key);
    pi = pi->prox;
  }
  printf("[ %d ]\n", pi->key);
}

bool SEARCH(KEY_TYPE key, Stack pi) {
  bool found = false;
  while (pi != NULL) {
    if (pi->key == key)
      found = true;
    pi = pi->prox;
  }
  return found;
}

int main() {
  Stack stack;

  stack = PUSH(1, stack);
  stack = PUSH(2, stack);
  stack = PUSH(3, stack);
  stack = PUSH(4, stack);
  stack = PUSH(5, stack);
  stack = PUSH(6, stack);

  SHOW(stack);

  stack = POP(stack);
  stack = POP(stack);

  SHOW(stack);

  if (SEARCH(6, stack))
    printf("\nFound\n");
  else
    printf("\nNot found\n");

  return 0;
}