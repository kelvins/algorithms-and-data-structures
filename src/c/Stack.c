/*
 *	Example of Stack implementation in C - Uses Sentinel
 */

#include <stdio.h>

#define MAX 10
#define ERROR -1

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} Record;

typedef struct {
  Record A[MAX + 1];
  int recordCount;
} Stack;

int initialize(Stack *p) {
  p->recordCount = 0;
  int i = 0;
  for (i; i < MAX - 2; i++) { // Fill the stack for testing
    p->A[i].key = i * 2; // This is an array of records (similar to a class),
                         // could have more fields, so it is defined this way
                         // A[i].key stores the value in the key field
  }
  p->recordCount = i;
}

bool push(int value, Stack *p) {
  if (p->recordCount < MAX) {
    p->A[p->recordCount].key = value;
    p->recordCount++;
    return true;
  } else {
    return false;
  }
}

bool pop(Stack *p) { p->recordCount--; }

void printStack(Stack *p) {
  int i = p->recordCount - 1;
  printf("\nStack:\n");
  for (i; i >= 0; i--) {
    printf("%d = [ %d ]\n", i, p->A[i].key);
  }
  printf("------------------\n");
}

int searchStack(int key, Stack *p) {
  p->A[p->recordCount].key = key;
  int temporary = 0;
  while (p->A[temporary].key != key)
    temporary++;
  if (temporary == p->recordCount)
    return ERROR;
  return temporary;
}

int main() {
  Stack stack;
  initialize(&stack);

  printStack(&stack);
  if (push(10, &stack)) {
    printf("Inserted successfully.");
  } else {
    printf("Stack is full");
  }

  printStack(&stack);
  pop(&stack);
  printStack(&stack);

  int temporary = searchStack(8, &stack);
  if (temporary != -1) {
    printf("Value 8 found at position %d in the stack\n", temporary);
  } else {
    printf("Value not found\n");
  }
}