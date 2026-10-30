/*
 *   Example of Doubly Linked List in C
 */

#include <stdio.h>
#include <stdlib.h>

/* Linked list using a head cell */

typedef struct Node Node;
struct Node {
  int data;
  struct Node *next;
  struct Node *previous;
};

/* Pointer 'p' is the head of the list */

void insertAtHead(int x, Node *p) /* Insert at the beginning of the list*/
{
  Node *newNode, *q;
  newNode = malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = p->next;
  /* Check whether the list is empty */
  if (p->next != NULL) {
    q = newNode->next;
    q->previous = newNode;
  }
  p->next = newNode;
  newNode->previous = p;
}

void append(int x, Node *p) /* Insert at the end of the list*/
{
  Node *q;
  Node *newNode;
  newNode = malloc(sizeof(Node));
  newNode->data = x;
  q = p;
  while (q->next != NULL)
    q = q->next;

  q->next = newNode;
  newNode->previous = q;
  newNode->next = NULL;
}

void findAndRemove(int y, Node *p) {
  Node *w, *q;
  w = p;
  q = p->next;
  while (q != NULL && q->data != y) {
    w = q;
    q = q->next;
  }
  if (q != NULL) {
    w->next = q->next;
    q->previous = w;
    free(q);
  } else {
    printf("\nList does not contain the item\n\n");
    system("pause");
  }
}

void print(Node *p) {
  Node *q;
  for (q = p->next; q != NULL; q = q->next)
    printf("%d  ", q->data);
}

void Menu() {
  printf("  Main Menu\n");
  printf("1 - Insert at the beginning\n");
  printf("2 - Insert at the end\n");
  printf("3 - Remove\n");
  printf("4 - Exit\n");
  printf("\nOption: ");
}

void freeList(Node *head) {
  Node *p;
  p = head;
  while (p != NULL) {
    Node *q = p->next; /* Save a reference to the next element */
    free(p);           /* Free the memory pointed to by p */
    p = q;             /* Make p point to the next element */
  }
}

int main() {
  Node *p;
  int op = 0, item;
  // Initialize the list
  p = malloc(sizeof(Node));
  p->previous = NULL;
  p->next = NULL;
  // end_initialize

  do {
    system("cls");
    printf("\nList contents: ");
    if (p->next != NULL) {
      print(p);
    } else {
      printf("EMPTY LIST");
    }
    printf("\n\n");
    Menu();
    scanf("%d", &op);
    switch (op) {
    case 1:
      printf("Insert at the beginning of the list: ");
      scanf("%d", &item);
      insertAtHead(item, p);
      break;
    case 2:
      printf("Insert at the last position of the list: ");
      scanf("%d", &item);
      append(item, p);
      break;
    case 3:
      if (p->next != NULL) {
        printf("Remove an item: ");
        scanf("%d", &item);
        findAndRemove(item, p);
      } else {
        printf("\nEMPTY LIST\n\n");
        system("pause");
      }
      break;
    case 4:
      break;
    default:
      printf("Invalid option!\n");
      system("pause");
      break;
    }

  } while (op != 4);
  freeList(p);
  return 0;
}
