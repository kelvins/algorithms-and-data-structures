/*
 *	Example of Sorted Sequential List implementation in C - Using
 *sentinel
 */

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int KEY_TYPE; // Define TIPOCHAVE as an alias for an integer type

typedef struct {
  KEY_TYPE key;
} Record;

typedef struct {
  Record A[MAX + 1]; // The extra position is used for the sentinel
  int elementCount;
} List;

void initializeList(List *L) {
  L->elementCount = 0; // Access the list through its memory address
  int i = 0;
  for (i; i < MAX - 2; ++i) { // Fill all but two slots, leaving room for more
    L->A[i].key = i * 2;
  }
  L->elementCount = MAX - 2;
  // (*L).nroElementos = 0; // This accesses the list itself, not the
  // pointer
}

/* The sentinel's purpose is to add the key at the end of the list, ensuring
 * the key is always found, even if it is in the last position.
 * If it is the last element, the key was not present in the original list.
 * This removes the 'if' from the loop and avoids several comparisons.
 */
int sentinelSearch(KEY_TYPE key,
                   List *L) { // Binary search could be used here and would be
                              // more appropriate.
  int i = 0;
  L->A[L->elementCount].key =
      key; // Assign the searched key/value to the last position of array A
  while (L->A[i].key != key) // Scan array A for the searched key/value;
                             // otherwise this is the sentinel
    i++;
  if (i == L->elementCount) // Reaching the end means the value was not found;
                            // return ERROR (-1)
    return ERRO;
  return i; // Otherwise, return the position of the value/key in the array
}

bool insertSorted(Record reg, List *L) {
  int i = 0;
  if (L->elementCount >= MAX)
    return false;
  L->A[L->elementCount].key = reg.key;
  while (L->A[i].key < reg.key)
    i++;
  int p = L->elementCount - 1;
  while (p >= i) {
    L->A[p + 1] = L->A[p];
    p--;
  }
  L->A[i] = reg;
  L->elementCount++;
  return true;
}

bool deleteValue(Record reg, List *L) {
  int position = sentinelSearch(reg.key, L);
  if (position >= 0) {
    for (position; position < L->elementCount; position++) {
      L->A[position] = L->A[position + 1];
    }
    L->elementCount--;
    return true;
  } else {
    return false;
  }
}

void printList(List *L) {
  int i = 0;
  for (i; i < L->elementCount;
       ++i) { // Visit and display every value in the array
    printf("%d, ", L->A[i].key);
  }
  printf("\n\n");
}

int main() {

  List List;
  initializeList(&List);

  printf("Value 10 found at position: %d\n\n", sentinelSearch(10, &List));
  printList(&List);

  Record reg;
  reg.key = 7;
  printf("Insert value: %d\n", reg.key);
  insertSorted(reg, &List);
  printList(&List);

  reg.key = 12;
  printf("Delete value: %d\n", reg.key);
  deleteValue(reg, &List);
  printList(&List);

  return 0;
}