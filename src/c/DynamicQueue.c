/*
 *	Implementation of a Dynamic Linked/Chained Queue Structure in C
 */

#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE;

typedef struct Node {
  KEY_TYPE key;
  struct Node *prox;
} *NodePointer;

NodePointer newNode(KEY_TYPE key) {
  NodePointer temporary = (NodePointer)malloc(sizeof(Node));
  temporary->key = key;
  temporary->prox = NULL;
  return temporary;
}

NodePointer insert(KEY_TYPE key, NodePointer node) {
  NodePointer temporary = newNode(key);
  temporary->prox = node;
  return temporary;
}

void printQueue(NodePointer node) {
  while (node != NULL) {
    printf("[%d]->", node->key);
    node = node->prox;
  }
  printf("\n");
}

void remove(NodePointer node) {
  NodePointer previousNode = node;
  while (node->prox != NULL) {
    previousNode = node;
    node = node->prox;
  }
  previousNode->prox = NULL;
  free(node);
}

int queueLength(NodePointer node) {
  int cont = 0;
  while (node != NULL) {
    cont++;
    node = node->prox;
  }
  return cont;
}

int main() {
  NodePointer queue = newNode(5);
  queue = insert(8, queue);
  queue = insert(1, queue);
  queue = insert(3, queue);
  queue = insert(5, queue);
  queue = insert(4, queue);
  queue = insert(2, queue);

  printQueue(queue);
  remove(queue);
  printQueue(queue);
  remove(queue);
  printQueue(queue);

  printf("Queue size: %d\n", queueLength(queue));
  return 0;
}