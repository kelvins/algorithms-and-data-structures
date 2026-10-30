/*
 *   Example of Doubly Linked List in C
 */

#include <stdio.h>
#include <stdlib.h>

/* Linked list using a head cell */

typedef struct cel Node;
struct cel {
  int data;
  struct cel *prox;
  struct cel *previous;
};

/* Pointer 'p' is the head of the list */

void insertAtHead(int x, Node *p) /* Insere no inicio da lista*/
{
  Node *newNode, *q;
  newNode = malloc(sizeof(Node));
  newNode->data = x;
  newNode->prox = p->prox;
  /* Check whether the list is empty */
  if (p->prox != NULL) {
    q = newNode->prox;
    q->previous = newNode;
  }
  p->prox = newNode;
  newNode->previous = p;
}

void append(int x, Node *p) /* Insere no final da lista*/
{
  Node *q;
  Node *newNode;
  newNode = malloc(sizeof(Node));
  newNode->data = x;
  q = p;
  while (q->prox != NULL)
    q = q->prox;

  q->prox = newNode;
  newNode->previous = q;
  newNode->prox = NULL;
}

void findAndRemove(int y, Node *p) {
  Node *w, *q;
  w = p;
  q = p->prox;
  while (q != NULL && q->data != y) {
    w = q;
    q = q->prox;
  }
  if (q != NULL) {
    w->prox = q->prox;
    q->previous = w;
    free(q);
  } else {
    printf("\nList does not contain the item\n\n");
    system("pause");
  }
}

void print(Node *p) {
  Node *q;
  for (q = p->prox; q != NULL; q = q->prox)
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

void libera(Node *ini) {
  Node *p;
  p = ini;
  while (p != NULL) {
    Node *q = p->prox; /* Save a reference to the next element */
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
  p->prox = NULL;
  // fim_inicializa

  do {
    system("cls");
    printf("\nList contents: ");
    if (p->prox != NULL) {
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
      if (p->prox != NULL) {
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
  libera(p);
  return 0;
}
