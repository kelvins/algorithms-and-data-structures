/*
 *	Example of Queue implementation in C
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
} Queue;

void initialize(Queue *queue) {
  int i = 0;
  for (i; i < MAX - 2; i++) {
    queue->A[i].key = i * 2;
  }
  queue->recordCount = i;
}

void printQueue(Queue *queue) {
  int i = 0;
  printf("QUEUE:\n");
  for (i; i < queue->recordCount; i++) {
    printf("[ %d ] ", queue->A[i].key);
  }
  printf("\n\n");
}

bool enqueue(KEY_TYPE key, Queue *queue) {
  if (queue->recordCount >= MAX)
    return false;
  queue->A[queue->recordCount].key = key;
  queue->recordCount++;
  return true;
}

bool dequeue(Queue *queue) {
  if (queue->recordCount <= 0)
    return false;
  int i = 1;
  for (i; i < queue->recordCount; i++) {
    queue->A[i - 1].key = queue->A[i].key;
  }
  queue->recordCount--;
  return true;
}

int searchQueue(KEY_TYPE key, Queue *queue) {
  queue->A[queue->recordCount].key =
      key; // Place ch at the last position for sentinel search
  int i = 0;
  while (queue->A[i].key != key)
    i++;
  if (i >= queue->recordCount)
    return ERROR;
  return i;
}

int main() {
  Queue queue;
  initialize(&queue);
  printQueue(&queue);

  enqueue(15, &queue);
  printQueue(&queue);

  dequeue(&queue);
  printQueue(&queue);

  printf("The searched key is at position %d in the queue\n\n",
         searchQueue(8, &queue));
  return 0;
}