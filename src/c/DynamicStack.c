/*
 *	Dynamic Stack using a Linked List in C
 */

#include <malloc.h>
#include <stdio.h>

#define ERROR -1

typedef int KEY_TYPE;

typedef struct EdgeNode {
  KEY_TYPE key;
  struct EdgeNode *next;
} *Stack;

Stack CREATE(KEY_TYPE key) {
  Stack newStack = (Stack)malloc(sizeof(Stack));
  newStack->key = key;
  newStack->next = NULL;
  return newStack;
}

Stack PUSH(KEY_TYPE key, Stack pi) {
  /*while( pi->next != NULL ){
          pi = pi->next;
  }*/
  Stack newNode = CREATE(key);
  // stack->next = newNode;
  newNode->next = pi;
  return newNode;
}

Stack POP(Stack pi) {
  Stack rest = pi->next;
  free(pi);
  return rest;
}

void SHOW(Stack pi) {
  printf("STACK:\n");
  while (pi->next != NULL) {
    printf("[ %d ]\n", pi->key);
    pi = pi->next;
  }
  printf("[ %d ]\n", pi->key);
}

bool SEARCH(KEY_TYPE key, Stack pi) {
  bool found = false;
  while (pi != NULL) {
    if (pi->key == key)
      found = true;
    pi = pi->next;
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
