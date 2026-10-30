/*
 *
 *	Linked List with Head Node, Circular and Sorted (Dynamic Implementation)
 *
 */

#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE; // Key type for each list node

// Data structure representing each list node
typedef struct Node {
  KEY_TYPE key;
  struct Node *next;
} Node, *NodePointer;

typedef struct {
  NodePointer head; // Head node
} List;

void initializeList(List *L) {
  // The head node keeps the list from being empty and can also be used as a
  // sentinel
  L->head = (NodePointer)malloc(sizeof(Node));
  L->head->next =
      L->head; // Initially points to itself because the list is circular
}

// Since this method does not modify the list, it can receive a copy instead
// of a pointer to it
NodePointer linearSearch(KEY_TYPE key, List L, NodePointer *previous) {
  *previous = L.head; // Since this is a copy, use dot (.) instead of arrow
                      // (->); previous stores the pointer to the matching node
  NodePointer current = L.head->next;
  L.head->key = key; // Store the value in the head node as a sentinel; it will
                     // be the last value compared
  while (current->key != key) {
    *previous = current;     // Store the pointer to the node
    current = current->next; // Move to the next node
  }
  if (current != L.head) // If this is not the head node, the value was found
    return current;      // Return the node
  else
    return NULL; // Otherwise, return NULL
}

bool remove(KEY_TYPE key, List *L) {
  NodePointer temporary, previous;
  temporary =
      linearSearch(key, *L,
                   &previous); // Find the value to remove. previous is passed
                               // by address so the search function can update
                               // it to hold the previous node
  if (temporary == NULL)
    return false;
  previous->next = temporary->next;
  free(temporary);
  return true;
}

void insert(KEY_TYPE key, List *L) {
  NodePointer previous =
      L->head; // previous stores a pointer to the previous node
  NodePointer current =
      L->head->next; // current stores a pointer to the current node

  while (current->key < key && current != L->head) {
    previous =
        current; // Store the current node pointer; it becomes the previous node
    current = current->next; // Move to the next node
  }
  // The correct position in ascending order has been found
  NodePointer newNode = (NodePointer)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = current;
  previous->next = newNode;
}

NodePointer printList(List L) {
  NodePointer current =
      L.head->next; // current receives the first element after the head node
  while (current !=
         L.head) { // If it is not the head node, the list is not empty
    printf("[ %d ]->", current->key); // Display the node value
    current = current->next;          // Move to the next node
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
    printf("Value %d found.\n", value);
  else
    printf("Value %d not found.\n", value);

  return 0;
}
