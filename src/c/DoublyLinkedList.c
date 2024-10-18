/*
*   Exemplo Lista Duplamente Encadeada em C
*/


#include <stdio.h>
#include <stdlib.h>

/* Lista encadeada utilizando celula cabeça */

typedef struct cel celula;
struct cel{
    int dado;
    struct cel *prox;
    struct cel *ant;
};

/* O ponteiro 'p' é a cabeça da lista*/

void insereInicio(int x, celula *p) /* Insere no inicio da lista*/
{
   celula *nova, *q;
   nova = malloc (sizeof (celula));
   nova->dado = x;
   nova->prox = p->prox;
   /* verifica se a lista está vazia*/
   if (p->prox != NULL)
   {
      q = nova->prox;
      q->ant = nova;
   }
   p->prox = nova;
   nova->ant = p;
}

void insereUltimo(int x, celula *p) /* Insere no final da lista*/
{
	celula *q;
	celula *nova;
	nova = malloc (sizeof (celula));
	nova->dado = x;
	q = p;
	while (q->prox != NULL)
		q = q->prox;

	q->prox = nova;
	nova->ant = q;
	nova->prox = NULL;
}


void buscaEremove (int y, celula *p)
{
   celula *w, *q;
   w = p;
   q = p->prox;
   while (q != NULL && q->dado != y) {
      w = q;
      q = q->prox;
   }
   if (q != NULL) {
      w->prox = q->prox;
      q->ant = w;
      free (q);
   }
    else{
        printf("\nLista nao contem item\n\n");
        system("pause");
   }
}


void imprime (celula *p)
{
    celula *q;
    for (q = p->prox; q != NULL; q = q->prox)
        printf ("%d  ", q->dado);
}

void Menu ()
{
    printf("  Menu Principal\n");
    printf("1 - Insere inicio\n");
    printf("2 - Insere ultimo\n");
    printf("3 - Retira\n");
    printf("4 - Sair\n");
    printf("\nOpcao: ");
}

void libera (celula *ini)
{
    celula *p;
    p=ini;
    while (p != NULL) {
        celula *q = p->prox; /* guarda referência para o próximo elemento*/
        free(p); /* libera a memória apontada por p */
        p = q; /* faz p apontar para o próximo */
    }
}


int main()
{
    celula  *p;
    int op = 0,item;
    //inicializa lista
    p = malloc (sizeof (celula));
    p->ant = NULL;
    p->prox = NULL;
    //fim_inicializa

    do{
        system("cls");
        printf("\nConteudo da lista: ");
        if (p->prox != NULL){
            imprime(p);
        }
        else{
            printf("Lista VAZIA");
        }
        printf("\n\n");
        Menu();
        scanf("%d",&op);
        switch (op){
            case 1:
                printf("Insere no inicio da lista: ");
                scanf("%d",&item);
                insereInicio(item,p);
                break;
            case 2:
               printf("Insere na ultima posicao da lista: ");
               scanf("%d",&item);
               insereUltimo(item,p);
               break;
            case 3:
                if (p->prox != NULL){
                    printf("Retirar um elemento: ");
                    scanf("%d",&item);
                    buscaEremove(item,p);
                }
                else{
                    printf("\nLista VAZIA\n\n");
                    system("pause");
                }
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                system("pause");
                break;
        }

    }while(op!=4);
    libera(p);
    return 0;
}



//  In english 

/*
*   Example of a Doubly Linked List in C
*/

// Doubly linked list node structure
// typedef struct Node {
//     int data;                  // Data stored in the node
//     struct Node *next;        // Pointer to the next node
//     struct Node *prev;        // Pointer to the previous node
// } Node;

// // Function to insert a new node at the beginning of the list
// void insertAtBeginning(int value, Node *head) {
//     Node *newNode = malloc(sizeof(Node)); // Allocate memory for new node
//     newNode->data = value;                // Set the data for the new node
//     newNode->next = head->next;           // Point to the current first node

//     // Check if the list is not empty
//     if (head->next != NULL) {
//         head->next->prev = newNode;       // Update the previous pointer of the current first node
//     }

//     head->next = newNode;                 // Update the head to point to the new node
//     newNode->prev = head;                 // Set the previous pointer of the new node to head
// }

// // Function to insert a new node at the end of the list
// void insertAtEnd(int value, Node *head) {
//     Node *newNode = malloc(sizeof(Node)); // Allocate memory for new node
//     newNode->data = value;                // Set the data for the new node
//     newNode->next = NULL;                 // New node will be the last node

//     Node *current = head;                 // Start at the head
//     while (current->next != NULL) {
//         current = current->next;          // Traverse to the last node
//     }

//     current->next = newNode;              // Link the last node to the new node
//     newNode->prev = current;              // Set the previous pointer of the new node
// }

// // Function to search for a node with the specified value and remove it
// void searchAndRemove(int value, Node *head) {
//     Node *current = head->next;           // Start at the first node

//     while (current != NULL && current->data != value) {
//         current = current->next;          // Traverse the list
//     }

//     if (current != NULL) {                 // Node found
//         current->prev->next = current->next; // Bypass the current node
//         if (current->next != NULL) {       // If not the last node
//             current->next->prev = current->prev; // Link the next node to the previous node
//         }
//         free(current);                     // Free memory of the removed node
//     } else {
//         printf("\nList does not contain the item\n\n");
//         system("pause");
//     }
// }

// // Function to print the contents of the list
// void printList(Node *head) {
//     Node *current;
//     for (current = head->next; current != NULL; current = current->next) {
//         printf("%d  ", current->data);
//     }
// }

// // Function to display the main menu
// void displayMenu() {
//     printf("  Main Menu\n");
//     printf("1 - Insert at beginning\n");
//     printf("2 - Insert at end\n");
//     printf("3 - Remove an item\n");
//     printf("4 - Exit\n");
//     printf("\nOption: ");
// }

// // Function to free the allocated memory for the list
// void freeList(Node *head) {
//     Node *current = head;
//     while (current != NULL) {
//         Node *nextNode = current->next; // Store the reference to the next node
//         free(current);                  // Free memory of the current node
//         current = nextNode;            // Move to the next node
//     }
// }

// int main() {
//     Node *head = malloc(sizeof(Node)); // Initialize the head of the list
//     head->prev = NULL;
//     head->next = NULL;

//     int option = 0, item; // Variables for menu option and item input

//     do {
//         system("cls"); // Clear the screen
//         printf("\nContents of the list: ");
//         if (head->next != NULL) {
//             printList(head); // Print the list if not empty
//         } else {
//             printf("List is EMPTY");
//         }
//         printf("\n\n");

//         displayMenu(); // Show menu options
//         scanf("%d", &option); // Get user input for menu option
//         switch (option) {
//             case 1:
//                 printf("Insert at the beginning of the list: ");
//                 scanf("%d", &item);
//                 insertAtBeginning(item, head); // Insert at the beginning
//                 break;
//             case 2:
//                 printf("Insert at the end of the list: ");
//                 scanf("%d", &item);
//                 insertAtEnd(item, head); // Insert at the end
//                 break;
//             case 3:
//                 if (head->next != NULL) {
//                     printf("Remove an item: ");
//                     scanf("%d", &item);
//                     searchAndRemove(item, head); // Remove specified item
//                 } else {
//                     printf("\nList is EMPTY\n\n");
//                     system("pause");
//                 }
//                 break;
//             case 4:
//                 break;
//             default:
//                 printf("Invalid option!\n");
//                 system("pause");
//                 break;
//         }
//     } while (option != 4); // Continue until user chooses to exit

//     freeList(head); // Free the allocated memory for the list
//     return 0;
// }
