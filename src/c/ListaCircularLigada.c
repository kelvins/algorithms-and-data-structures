/*
*
* Circular Ordered Linked List (Dynamic Implementation) with a Head Node
* Kelvin Salton do Prado - 2015
*
*/

#include <stdio.h>
#include <malloc.h>

typedef int KEY_TYPE; // Type of ID for each node in the list

// Data structure representing each node in the list
typedef struct NODE {
    KEY_TYPE key;
    struct NODE* next;
} NODE, *POINTER;

typedef struct {
    POINTER head; // Head node
} LIST;

void initialize(LIST* L) {
    // The head node prevents the list from becoming empty and can also be used as a sentinel
    L->head = (POINTER)malloc(sizeof(NODE));
    L->head->next = L->head; // Starts pointing to itself since it's circular
}

// Since this method will not change the list, a copy of it can be passed, and not necessarily a pointer to it
POINTER sequentialSearch(KEY_TYPE key, LIST L, POINTER* prev) {
    *prev = L.head; // Being a copy, we can use a dot (.) instead of an arrow (->); prev stores a pointer to the found node
    POINTER current = L.head->next;
    L.head->key = key; // Stores the value in the head node to be used as a sentinel; it will be the last to be compared
    while (current->key != key) {
        *prev = current; // Stores the pointer to the node
        current = current->next; // Moves to the next node
    }
    if (current != L.head) // If the node is not the head node, it means it was found
        return current; // Returns the node
    else
        return NULL; // Otherwise, it was not found, returns NULL
}

bool delete(KEY_TYPE key, LIST* L) {
    POINTER aux, prev;
    aux = sequentialSearch(key, *L, &prev); // Searches for the value to delete; prev is passed as a memory address so that the search function can modify it to store the previous value
    if (aux == NULL)
        return false; // Not found
    prev->next = aux->next; // The previous node points to the next one, which is where the node to be deleted is pointing
    free(aux); // Frees memory
    return true;
}

void insert(KEY_TYPE key, LIST* L) {
    POINTER prev = L->head; // prev stores the pointer to the previous node
    POINTER current = L->head->next; // current stores the pointer to the current node

    while (current->key < key && current != L->head) {
        prev = current; // Stores the pointer to the current node, which will become the previous one
        current = current->next; // Moves to the next node
    }

    // When the correct position in ascending order is found
    POINTER new_node = (POINTER)malloc(sizeof(NODE)); // Creates a new node
    new_node->key = key; // Sets the key in the node
    new_node->next = current; // Points to the next node
    prev->next = new_node; // The previous node points to the new node
}

void showList(LIST L) {
    POINTER current = L.head->next; // Current receives the first element after the head node
    while (current != L.head) { // If it's not the head node, the list is not empty
        printf("[ %d ]->", current->key); // Shows the value of the node
        current = current->next; // Moves to the next node
    }
    printf("\n");
}

int main() {

    LIST list;
    initialize(&list);

    insert(4, &list);
    insert(6, &list);
    insert(2, &list);
    insert(3, &list);
    insert(1, &list);
    insert(5, &list);

    showList(list);

    delete(2, &list);
    delete(4, &list);
    delete(6, &list);

    showList(list);

    // Example of searching in the list
    POINTER aux;
    int value = 2;
    if (sequentialSearch(value, list, &aux) != NULL)
        printf("Value %d found.\n", value);
    else
        printf("Value %d not found.\n", value);

    return 0;
}
