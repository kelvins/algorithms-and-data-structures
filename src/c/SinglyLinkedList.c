#include <stdlib.h>
#include <stdio.h>

typedef struct tno {
    int dado;
    struct tno * anterior;
    struct tno * proximo;
} tipoNo;

typedef tipoNo * pnoh;

typedef struct {
    int tamanho;
    pnoh primeiro;
    pnoh ultimo;
} tcabec;

typedef tcabec * TLista;

TLista criaLista() {
    TLista c = (tcabec*) malloc(sizeof(tcabec));

    c->tamanho = 0;
    c->primeiro = NULL;
    c->ultimo = NULL;

    return c;
}

TLista appendLista(TLista lst, int dado) {
    pnoh novono = (tipoNo*) malloc(sizeof(tipoNo));

    novono->dado = dado;
    novono->anterior = lst->ultimo;
    novono->proximo = NULL;

    if (lst->tamanho == 0) {
        lst->primeiro = novono;
    } else {
        lst->ultimo->proximo = novono;
    }

    lst->ultimo = novono;
    lst->tamanho++;

    return lst;
}

int lenLista(TLista lst) {
    return lst->tamanho;
}

int primLista(TLista lst) {
    return lst->primeiro->dado;
}

int ultLista(TLista lst) {
    return lst->ultimo->dado;
}

TLista insertLista(TLista lst, int i, int dado)
{
    int tam = lenLista(lst);

    if ((i < 0) || (i > tam)) {
        return NULL;
    }

    if ((lenLista(lst) == 0) || (i == tam)) {
        appendLista(lst, dado);
    } else {
        pnoh novono = (tipoNo*) malloc(sizeof(tipoNo));
        novono->dado = dado;

        if (i == 0) {
            novono->proximo = lst->primeiro;
            lst->primeiro = novono;
        } else {
            pnoh aux = lst->primeiro;
            int pos = 0;

            while (pos != (i - 1))
            {
                aux = aux->proximo;
                pos++;
            }
            novono->proximo = aux->proximo;
            aux->proximo = novono;
        }

        lst->tamanho++;
    }

    return lst;
}

pnoh infoLista(TLista lst, int i) {
    int tam = lenLista(lst);

    if ((tam == 0) || (i < 0) || (i > tam)) {
        return NULL;
    }

    if (i == 0) {
        return lst->primeiro;
    }

    if (i == tam - 1) {
        return lst->ultimo;
    }

    pnoh aux = lst->primeiro;
    int pos = 0;

    while (pos != i) {
        aux = aux->proximo;
        pos++;
    }

    return aux;
}

void removeLista(TLista lst, int i) {
    int tam = lenLista(lst);

    if ((i < 0) || (i > tam) || (tam == 0)) {
        printf("Erro: indice inexistente dentro da Lista.");
        return;
    }

    if (tam == 1) {
        pnoh aux = lst->primeiro;
        lst->primeiro = NULL;
        lst->ultimo = NULL;
        lst->tamanho--;

        free(aux);
    } else {
        if (i == 0) {
            pnoh aux = lst->primeiro;
            lst->primeiro = aux->proximo;
            lst->tamanho--;

            free(aux);
        } else {
            if (i == tam - 1) {
                pnoh aux = lst->ultimo;

                pnoh penultimo = lst->primeiro;
                int pos = 0;

                while (pos != i - 1) {
                    penultimo = penultimo->proximo;
                    pos++;
                }

                penultimo->proximo = NULL;
                lst->ultimo = penultimo;

                lst->tamanho--;

                free(aux);
            } else {
                pnoh anterior = lst->primeiro;
                int pos = 0;

                while (pos != i - 1) {
                    anterior = anterior->proximo;
                    pos++;
                }

                pnoh aux = anterior->proximo;
                anterior->proximo = aux->proximo;
                lst->tamanho--;

                free(aux);
            }
        }
    }
}

int indexLista(TLista lst, int dado) {
    int tam = lenLista(lst);
    int i, dadolst;
    pnoh no_dadolst;

    if (tam == 0) {
        return -1;
    }

    i = 0;
    no_dadolst = infoLista(lst, i);
    dadolst = no_dadolst->dado;
    while ((i < tam) && (dado != dadolst)) {
        i++;
        no_dadolst = infoLista(lst, i);
        dadolst = no_dadolst->dado;
    }

    if (i < tam) {
        return i;
    }

    return -1;
}

TLista clearLista(TLista lst) {
    int tam = lenLista(lst);

    if (tam == 0) {
        return lst;
    }

    while (lenLista(lst) > 0) {
        removeLista(lst, 0);
    }

    return lst;
}

TLista clonaLista(TLista lst) {
    TLista clone = criaLista();
    int tam = lenLista(lst);

    if (tam == 0) {
        return clone;
    }

    for (int i = 0; i < tam; i++) {
        pnoh no = infoLista(lst, i);
        if (no != NULL) {
            appendLista(clone, no->dado);
        }
    }

    return clone;
}

int main() {
    TLista lista = criaLista();
    appendLista(lista, 3);
    appendLista(lista, 5);
    appendLista(lista, 7);

    printf("Lista criada e adicionado 3 numeros\n");
    int tamanho = lenLista(lista);
    int primeiro = primLista(lista);
    int ultimo = ultLista(lista);
    pnoh valor = infoLista(lista, 1);
    int valor_dado = valor->dado;
    printf("Tamanho da lista: %d\nPrimeiro da Lista: %d\nUltimo da Lista: %d\nSegundo valor: %d\n", tamanho, primeiro, ultimo, valor_dado);

    insertLista(lista, 2, 6);
    valor = infoLista(lista, 2);
    valor_dado = valor->dado;
    printf("Adicionando 6 na posição 2: %d\n", valor_dado);

    removeLista(lista, 1);
    tamanho = lenLista(lista);
    printf("Novo tamanho após adicionar e remover: %d\n", tamanho);

    int index = indexLista(lista, 3);
    printf("Index do elemento com valor 3 na lista: %d\n", index);

    TLista cloneLista = clonaLista(lista);
    printf("Lista Duplicada\n");

    clearLista(lista);
    printf("Lista Apagada");

    return 0;
}

//  In english 


// Define a node structure
// typedef struct Node {
//     int data;                 // Data contained in the node
//     struct Node* previous;    // Pointer to the previous node
//     struct Node* next;        // Pointer to the next node
// } NodeType;

// typedef NodeType* NodePointer;

// // Define a list header structure
// typedef struct {
//     int size;                 // Size of the list
//     NodePointer first;        // Pointer to the first node
//     NodePointer last;         // Pointer to the last node
// } ListHeader;

// typedef ListHeader* List;

// // Function to create a new list
// List createList() {
//     List list = (ListHeader*)malloc(sizeof(ListHeader));

//     list->size = 0;          // Initialize size to 0
//     list->first = NULL;      // Initialize first pointer to NULL
//     list->last = NULL;       // Initialize last pointer to NULL

//     return list;
// }

// // Function to append a new element to the list
// List appendList(List lst, int data) {
//     NodePointer newNode = (NodeType*)malloc(sizeof(NodeType));

//     newNode->data = data;         // Set the data of the new node
//     newNode->previous = lst->last; // Set previous pointer to the current last node
//     newNode->next = NULL;         // Set next pointer to NULL

//     if (lst->size == 0) {
//         lst->first = newNode;      // If the list is empty, set first pointer
//     } else {
//         lst->last->next = newNode; // Link the new node to the end of the list
//     }

//     lst->last = newNode;          // Update last pointer to the new node
//     lst->size++;                   // Increment the size of the list

//     return lst;
// }

// // Function to get the size of the list
// int lengthList(List lst) {
//     return lst->size;
// }

// // Function to get the first element of the list
// int firstList(List lst) {
//     return lst->first->data;
// }

// // Function to get the last element of the list
// int lastList(List lst) {
//     return lst->last->data;
// }

// // Function to insert a new element at a specific index
// List insertList(List lst, int index, int data) {
//     int size = lengthList(lst);

//     if ((index < 0) || (index > size)) {
//         return NULL;  // Return NULL if index is invalid
//     }

//     if ((lengthList(lst) == 0) || (index == size)) {
//         appendList(lst, data);  // Append to the end if index is size
//     } else {
//         NodePointer newNode = (NodeType*)malloc(sizeof(NodeType));
//         newNode->data = data;

//         if (index == 0) {
//             newNode->next = lst->first;  // Insert at the beginning
//             lst->first = newNode;
//         } else {
//             NodePointer aux = lst->first;
//             int pos = 0;

//             while (pos != (index - 1)) {
//                 aux = aux->next;  // Traverse to the node before the insert position
//                 pos++;
//             }
//             newNode->next = aux->next;  // Link new node to the next node
//             aux->next = newNode;         // Link the previous node to the new node
//         }

//         lst->size++;  // Increment the size of the list
//     }

//     return lst;
// }

// // Function to retrieve a node at a specific index
// NodePointer infoList(List lst, int index) {
//     int size = lengthList(lst);

//     if ((size == 0) || (index < 0) || (index > size)) {
//         return NULL;  // Return NULL if index is invalid
//     }

//     if (index == 0) {
//         return lst->first;  // Return first node if index is 0
//     }

//     if (index == size - 1) {
//         return lst->last;   // Return last node if index is last
//     }

//     NodePointer aux = lst->first;
//     int pos = 0;

//     while (pos != index) {
//         aux = aux->next;  // Traverse to the specified index
//         pos++;
//     }

//     return aux;  // Return the node at the specified index
// }

// // Function to remove a node at a specific index
// void removeList(List lst, int index) {
//     int size = lengthList(lst);

//     if ((index < 0) || (index > size) || (size == 0)) {
//         printf("Error: index does not exist in the list.");
//         return;  // Print error if index is invalid
//     }

//     if (size == 1) {
//         NodePointer aux = lst->first;
//         lst->first = NULL;  // Empty the list
//         lst->last = NULL;
//         lst->size--;

//         free(aux);  // Free the memory of the removed node
//     } else {
//         if (index == 0) {
//             NodePointer aux = lst->first;
//             lst->first = aux->next;  // Update first node
//             lst->size--;

//             free(aux);  // Free the memory of the removed node
//         } else {
//             if (index == size - 1) {
//                 NodePointer aux = lst->last;

//                 NodePointer penultimate = lst->first;
//                 int pos = 0;

//                 while (pos != index - 1) {
//                     penultimate = penultimate->next;  // Find the penultimate node
//                     pos++;
//                 }

//                 penultimate->next = NULL;  // Update the penultimate node's next pointer
//                 lst->last = penultimate;    // Update last pointer

//                 lst->size--;

//                 free(aux);  // Free the memory of the removed node
//             } else {
//                 NodePointer previous = lst->first;
//                 int pos = 0;

//                 while (pos != index - 1) {
//                     previous = previous->next;  // Find the node before the one to be removed
//                     pos++;
//                 }

//                 NodePointer aux = previous->next;
//                 previous->next = aux->next;  // Bypass the removed node
//                 lst->size--;

//                 free(aux);  // Free the memory of the removed node
//             }
//         }
//     }
// }

// // Function to find the index of a specific value
// int indexList(List lst, int data) {
//     int size = lengthList(lst);
//     int i, listData;
//     NodePointer nodeData;

//     if (size == 0) {
//         return -1;  // Return -1 if the list is empty
//     }

//     i = 0;
//     nodeData = infoList(lst, i);
//     listData = nodeData->data;
//     while ((i < size) && (data != listData)) {
//         i++;
//         nodeData = infoList(lst, i);  // Get next node data
//         listData = nodeData->data;
//     }

//     if (i < size) {
//         return i;  // Return the index if found
//     }

//     return -1;  // Return -1 if not found
// }

// // Function to clear the list
// List clearList(List lst) {
//     int size = lengthList(lst);

//     if (size == 0) {
//         return lst;  // Return if the list is already empty
//     }

//     while (lengthList(lst) > 0) {
//         removeList(lst, 0);  // Remove all elements
//     }

//     return lst;
// }

// // Function to clone the list
// List cloneList(List lst) {
//     List clone = createList();
//     int size = lengthList(lst);

//     if (size == 0) {
//         return clone;  // Return an empty clone if the list is empty
//     }

//     for (int i = 0; i < size; i++) {
//         NodePointer node = infoList(lst, i);
//         if (node != NULL) {
//             appendList(clone, node->data);  // Append data to the clone list
//         }
//     }

//     return clone;  // Return the cloned list
// }

// // Main function to demonstrate the list operations
// int main() {
//     List list = createList();
//     appendList(list, 3);
//     appendList(list, 5);
//     appendList(list, 7);

//     printf("List created and added 3 numbers\n");
//     int size = lengthList(list);
//     int first = firstList(list);
//     int last = lastList(list);
//     NodePointer value = infoList(list, 1);
//     int valueData = value->data;
//     printf("Size of the list: %d\nFirst element of the list: %d\nLast element of the list: %d\nSecond value: %d\n", size, first, last, valueData);

//     insertList(list, 2, 6);
//     value = infoList(list, 2);
//     valueData = value->data;
//     printf("Adding 6 at position 2: %d\n", valueData);

//     removeList(list, 1);
//     size = lengthList(list);
//     printf("New size after adding and removing: %d\n", size);

//     int index = indexList(list, 3);
//     printf("Index of the element with value 3 in the list: %d\n", index);

//     List clonedList = cloneList(list);
//     printf("List duplicated\n");

//     clearList(list);
//     printf("List cleared\n");

//     return 0;
// }
