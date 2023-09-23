/*
*   Doubly Linked List Example in C
*   Luan Felipe dos S. da Silva
*/


#include <stdio.h>
#include <stdlib.h>

/* Linked list using a header cell */

typedef struct cell cell;
struct cell {
    int data;
    struct cell* next;
    struct cell* prev;
};

/* The 'p' pointer is the head of the list */

void insertAtBeginning(int x, cell* p) /* Inserts at the beginning of the list */
{
    cell* newCell, * q;
    newCell = malloc(sizeof(cell));
    newCell->data = x;
    newCell->next = p->next;
    /* Check if the list is empty */
    if (p->next != NULL) {
        q = newCell->next;
        q->prev = newCell;
    }
    p->next = newCell;
    newCell->prev = p;
}

void insertAtEnd(int x, cell* p) /* Inserts at the end of the list */
{
    cell* q;
    cell* newCell;
    newCell = malloc(sizeof(cell));
    newCell->data = x;
    q = p;
    while (q->next != NULL)
        q = q->next;

    q->next = newCell;
    newCell->prev = q;
    newCell->next = NULL;
}

void searchAndRemove(int y, cell* p)
{
    cell* w, * q;
    w = p;
    q = p->next;
    while (q != NULL && q->data != y) {
        w = q;
        q = q->next;
    }
    if (q != NULL) {
        w->next = q->next;
        q->prev = w;
        free(q);
    }
    else {
        printf("\nList does not contain item\n\n");
        system("pause");
    }
}

void printList(cell* p)
{
    cell* q;
    for (q = p->next; q != NULL; q = q->next)
        printf("%d  ", q->data);
}

void Menu()
{
    printf("  Main Menu\n");
    printf("1 - Insert at the beginning\n");
    printf("2 - Insert at the end\n");
    printf("3 - Remove\n");
    printf("4 - Exit\n");
    printf("\nOption: ");
}

void freeList(cell* head)
{
    cell* p;
    p = head;
    while (p != NULL) {
        cell* q = p->next; /* Store reference to the next element */
        free(p); /* Free memory pointed to by p */
        p = q; /* Make p point to the next one */
    }
}

int main()
{
    cell* head;
    int op = 0, item;
    // Initialize the list
    head = malloc(sizeof(cell));
    head->prev = NULL;
    head->next = NULL;
    // End of initialization

    do {
        system("cls");
        printf("\nList content: ");
        if (head->next != NULL) {
            printList(head);
        }
        else {
            printf("EMPTY List");
        }
        printf("\n\n");
        Menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("Insert at the beginning of the list: ");
            scanf("%d", &item);
            insertAtBeginning(item, head);
            break;
        case 2:
            printf("Insert at the end of the list: ");
            scanf("%d", &item);
            insertAtEnd(item, head);
            break;
        case 3:
            if (head->next != NULL) {
                printf("Remove an element: ");
                scanf("%d", &item);
                searchAndRemove(item, head);
            }
            else {
                printf("\nEMPTY List\n\n");
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
    freeList(head);
    return 0;
}
