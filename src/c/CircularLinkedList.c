/*
 *
 *	Linked List with Head Node, Circular and Sorted (Dynamic Implementation)
 *
 */

#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE; // Key type for each list node

// Data structure representing each list node
typedef struct EdgeNode {
  KEY_TYPE key;
  struct EdgeNode *prox;
} Node, *NodePointer;

typedef struct {
  NodePointer cab; // Head node
} List;

void initializeList(List *L) {
  // The head node keeps the list from being empty and can also be used as a
  // sentinela
  L->cab = (NodePointer)malloc(sizeof(Node));
  L->cab->prox =
      L->cab; // Initially points to itself because the list is circular
}

// Since this method does not modify the list, it can receive a copy instead
// of a pointer to it
NodePointer linearSearch(KEY_TYPE key, List L, NodePointer *previous) {
  *previous = L.cab; // Since this is a copy, use dot (.) instead of arrow (->);
                     // ant stores the pointer to the matching node
  NodePointer pos = L.cab->prox;
  L.cab->key = key; // Store the value in the head node as a sentinel; it will
                    // be the last value compared
  while (pos->key != key) {
    *previous = pos; // Store the pointer to the node
    pos = pos->prox; // Move to the next node
  }
  if (pos != L.cab) // If this is not the head node, the value was found
    return pos;     // Return the node
  else
    return NULL; // Otherwise, return NULL
}

bool remove(KEY_TYPE key, List *L) {
  NodePointer temporary, previous;
  temporary =
      linearSearch(key, *L,
                   &previous); // Find the value to remove. ant is passed by
                               // address so the search function can update it
                               // to hold the previous node
  if (temporary == NULL)
    return false;
  previous->prox = temporary->prox;
  free(temporary);
  return true;
}

void insert(KEY_TYPE key, List *L) {
  NodePointer previous = L->cab;  // ant stores a pointer to the previous node
  NodePointer pos = L->cab->prox; // pos stores a pointer to the current node

  while (pos->key < key && pos != L->cab) {
    previous =
        pos; // Store the current node pointer; it becomes the previous node
    pos = pos->prox; // Move to the next node
  }
  // The correct position in ascending order has been found
  NodePointer newNode = (NodePointer)malloc(sizeof(Node));
  newNode->key = key;
  newNode->prox = pos;
  previous->prox = newNode;
}

NodePointer printList(List L) {
  NodePointer pos =
      L.cab->prox;       // pos receives the first element after the head node
  while (pos != L.cab) { // If it is not the head node, the list is not empty
    printf("[ %d ]->", pos->key); // Display the node value
    pos = pos->prox;              // Move to the next node
  }
  printf("\n");
}

int main() {

  List list;
  initializeList(&list);

  insert(4, &list);
  insert(6, &list);
  insert(2, &list);
  insert(3, &list);
  insert(1, &list);
  insert(5, &list);

  printList(list);

  remove(2, &list);
  remove(4, &list);
  remove(6, &list);

  printList(list);

  // Example of searching the list
  NodePointer temporary;
  int value = 2;
  if (linearSearch(value, list, &temporary) != NULL)
    printf("Valor %d encontrado.\n", value);
  else
    printf("Valor %d não encontrado.\n", value);

  return 0;
}
