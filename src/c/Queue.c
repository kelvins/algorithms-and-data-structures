/*
 *	Example of Queue implementation in C
 */

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int KEY_TYPE;

typedef struct {
  KEY_TYPE key;
} Record;

typedef struct {
  Record A[MAX + 1];
  int recordCount;
} Queue;

void initialize(Queue *F) {
  int i = 0;
  for (i; i < MAX - 2; i++) {
    F->A[i].key = i * 2;
  }
  F->recordCount = i;
}

void printQueue(Queue *F) {
  int i = 0;
  printf("QUEUE:\n");
  for (i; i < F->recordCount; i++) {
    printf("[ %d ] ", F->A[i].key);
  }
  printf("\n\n");
}

bool enqueue(KEY_TYPE key, Queue *F) {
  if (F->recordCount >= MAX)
    return false;
  F->A[F->recordCount].key = key;
  F->recordCount++;
  return true;
}

bool dequeue(Queue *F) {
  if (F->recordCount <= 0)
    return false;
  int i = 1;
  for (i; i < F->recordCount; i++) {
    F->A[i - 1].key = F->A[i].key;
  }
  F->recordCount--;
  return true;
}

int searchQueue(KEY_TYPE key, Queue *F) {
  F->A[F->recordCount].key =
      key; // Place ch at the last position for sentinel search
  int i = 0;
  while (F->A[i].key != key)
    i++;
  if (i >= F->recordCount)
    return ERRO;
  return i;
}

int main() {
  Queue fi;
  initialize(&fi);
  printQueue(&fi);

  enqueue(15, &fi);
  printQueue(&fi);

  dequeue(&fi);
  printQueue(&fi);

  printf("The searched key is at position %d in the queue\n\n",
         searchQueue(8, &fi));
  return 0;
}