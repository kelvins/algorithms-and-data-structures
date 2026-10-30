#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *previous;
  struct Node *next;
} Node;

typedef Node *NodePointer;

typedef struct {
  int size;
  NodePointer first;
  NodePointer last;
} ListHeader;

typedef ListHeader *LinkedList;

LinkedList createList() {
  LinkedList c = (ListHeader *)malloc(sizeof(ListHeader));

  c->size = 0;
  c->first = NULL;
  c->last = NULL;

  return c;
}

LinkedList append(LinkedList list, int data) {
  NodePointer newNode = (Node *)malloc(sizeof(Node));

  newNode->data = data;
  newNode->previous = list->last;
  newNode->next = NULL;

  if (list->size == 0) {
    list->first = newNode;
  } else {
    list->last->next = newNode;
  }

  list->last = newNode;
  list->size++;

  return list;
}

int listLength(LinkedList list) { return list->size; }

int firstValue(LinkedList list) { return list->first->data; }

int lastValue(LinkedList list) { return list->last->data; }

LinkedList insertAt(LinkedList list, int i, int data) {
  int size = listLength(list);

  if ((i < 0) || (i > size)) {
    return NULL;
  }

  if ((listLength(list) == 0) || (i == size)) {
    append(list, data);
  } else {
    NodePointer newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (i == 0) {
      newNode->next = list->first;
      list->first = newNode;
    } else {
      NodePointer temporary = list->first;
      int pos = 0;

      while (pos != (i - 1)) {
        temporary = temporary->next;
        pos++;
      }
      newNode->next = temporary->next;
      temporary->next = newNode;
    }

    list->size++;
  }

  return list;
}

NodePointer nodeAt(LinkedList list, int i) {
  int size = listLength(list);

  if ((size == 0) || (i < 0) || (i > size)) {
    return NULL;
  }

  if (i == 0) {
    return list->first;
  }

  if (i == size - 1) {
    return list->last;
  }

  NodePointer temporary = list->first;
  int pos = 0;

  while (pos != i) {
    temporary = temporary->next;
    pos++;
  }

  return temporary;
}

void removeAt(LinkedList list, int i) {
  int size = listLength(list);

  if ((i < 0) || (i > size) || (size == 0)) {
    printf("Error: index does not exist in the list.");
    return;
  }

  if (size == 1) {
    NodePointer temporary = list->first;
    list->first = NULL;
    list->last = NULL;
    list->size--;

    free(temporary);
  } else {
    if (i == 0) {
      NodePointer temporary = list->first;
      list->first = temporary->next;
      list->size--;

      free(temporary);
    } else {
      if (i == size - 1) {
        NodePointer temporary = list->last;

        NodePointer secondLast = list->first;
        int pos = 0;

        while (pos != i - 1) {
          secondLast = secondLast->next;
          pos++;
        }

        secondLast->next = NULL;
        list->last = secondLast;

        list->size--;

        free(temporary);
      } else {
        NodePointer previous = list->first;
        int pos = 0;

        while (pos != i - 1) {
          previous = previous->next;
          pos++;
        }

        NodePointer temporary = previous->next;
        previous->next = temporary->next;
        list->size--;

        free(temporary);
      }
    }
  }
}

int indexOf(LinkedList list, int data) {
  int size = listLength(list);
  int i, dadolst;
  NodePointer nodeWithValue;

  if (size == 0) {
    return -1;
  }

  i = 0;
  nodeWithValue = nodeAt(list, i);
  dadolst = nodeWithValue->data;
  while ((i < size) && (data != dadolst)) {
    i++;
    nodeWithValue = nodeAt(list, i);
    dadolst = nodeWithValue->data;
  }

  if (i < size) {
    return i;
  }

  return -1;
}

LinkedList clearList(LinkedList list) {
  int size = listLength(list);

  if (size == 0) {
    return list;
  }

  while (listLength(list) > 0) {
    removeAt(list, 0);
  }

  return list;
}

LinkedList cloneList(LinkedList list) {
  LinkedList clone = createList();
  int size = listLength(list);

  if (size == 0) {
    return clone;
  }

  for (int i = 0; i < size; i++) {
    NodePointer node = nodeAt(list, i);
    if (node != NULL) {
      append(clone, node->data);
    }
  }

  return clone;
}

int main() {
  LinkedList list = createList();
  append(list, 3);
  append(list, 5);
  append(list, 7);

  printf("List created with 3 numbers\n");
  int size = listLength(list);
  int first = firstValue(list);
  int last = lastValue(list);
  NodePointer value = nodeAt(list, 1);
  int value = value->data;
  printf("List size: %d\nFirst item: %d\nLast item: "
         "%d\nSecond value: %d\n",
         size, first, last, value);

  insertAt(list, 2, 6);
  value = nodeAt(list, 2);
  value = value->data;
  printf("Adding 6 at position 2: %d\n", value);

  removeAt(list, 1);
  size = listLength(list);
  printf("New size after adding and removing: %d\n", size);

  int index = indexOf(list, 3);
  printf("Index of the element with value 3 in the list: %d\n", index);

  LinkedList cloneList = cloneList(list);
  printf("Cloned list\n");

  clearList(list);
  printf("List cleared");

  return 0;
}
