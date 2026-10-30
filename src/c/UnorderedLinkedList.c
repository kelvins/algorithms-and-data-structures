/*
 *	Example of Unordered Dynamic Linked List in C
 */

#include <malloc.h>
#include <stdio.h>

#define ERROR -1

typedef int KEY_TYPE;

typedef struct Node {
  KEY_TYPE key;
  struct Node *next;
} Record, *NodePointer;

NodePointer createRecord(KEY_TYPE key) {
  NodePointer record = (NodePointer)malloc(sizeof(NodePointer));
  record->key = key;
  record->next = NULL;
  return record;
}

NodePointer insertRecord(KEY_TYPE key, NodePointer record) {
  if (record == NULL)
    return createRecord(key); // Create a new record if the list has none
  while (record->next != NULL)
    record = record->next;
  record->next = createRecord(key);
  return NULL;
}

void printList(NodePointer record) {
  if (record == NULL)
    return;
  printf("%d, ", record->key);
  printList(record->next);
}

NodePointer linearSearch(KEY_TYPE key, NodePointer record) {
  while (record != NULL) {
    if (record->key == key)
      return record;
    record = record->next;
  }
  return NULL;
}

bool deleteRecord(KEY_TYPE key, NodePointer record) {
  NodePointer previous;
  while (record != NULL) {
    if (record->key == key) {
      previous->next = record->next;
      free(record);
      return true;
    }
    previous = record;
    record = record->next;
  }
  printf("\nKey %d not found.\n", key);
  return false;
}

int main() {
  NodePointer RG = insertRecord(23, RG);
  insertRecord(34, RG);
  insertRecord(12, RG);
  insertRecord(63, RG);
  insertRecord(45, RG);

  printList(RG);

  KEY_TYPE key = 64;
  if (linearSearch(key, RG) != NULL)
    printf("\nFound key %d\n", key);
  else
    printf("\nKey %d not found\n", key);

  deleteRecord(63, RG);
  printList(RG);

  printf("\n");
  deleteRecord(34, RG);
  printList(RG);
  return 0;
}