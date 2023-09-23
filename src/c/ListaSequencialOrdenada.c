/*
*	Example of Ordered Sequential List Implementation in C - Using a sentinel
*	Kelvin S. do Prado - 2015
*/

#include <stdio.h>

#define MAX 10
#define ERROR -1

typedef int KEY_TYPE; // Defines a type alias KEY_TYPE for an integer

typedef struct {
    KEY_TYPE key;
} RECORD;

typedef struct {
    RECORD A[MAX + 1]; // The +1 is for the position used by the 'sentinel'
    int nroElements;
} LIST;

void initialize(LIST* L) {
    L->nroElements = 0; // Accesses the list through the memory address
    int i = 0;
    for (i; i < MAX - 2; ++i) { // Fills the list up to -2 to leave space for insertion later
        L->A[i].key = i * 2;
    }
    L->nroElements = MAX - 2;
    // (*L).nroElements = 0; // In this case, it would access the list itself, not the pointer
}

/* The sentinel's function is to add the key to the end of the list, 
 * so it will always find the key even if it's in the last position of the list.
 * If it's the last element, it means it wasn't found.
 * This way, it eliminates the 'if' statement inside the loop, saving multiple comparisons.
 */ 
int sentinelSearch(KEY_TYPE ch, LIST* L) { // Binary search could be used here, which would be more appropriate.
    int i = 0;
    L->A[L->nroElements].key = ch; // Assigns the 'key'/value being searched to the last position of array A
    while (L->A[i].key != ch) // Scans the entire array A to find if the 'key'/value being searched is in the array (if not, it will be the sentinel)
        i++;
    if (i == L->nroElements) // If the value reached the end, it means the value was not found, so it returns ERROR (-1)
        return ERROR;
    return i; // Otherwise, it returns the position of the value/'key' in the array
}

bool insertOrdered(RECORD reg, LIST* L) {
    int i = 0;
    if (L->nroElements >= MAX)
        return false;
    L->A[L->nroElements].key = reg.key;
    while (L->A[i].key < reg.key)
        i++;
    int p = L->nroElements - 1;
    while (p >= i) {
        L->A[p + 1] = L->A[p];
        p--;
    }
    L->A[i] = reg;
    L->nroElements++;
    return true;
}

bool deleteValue(RECORD reg, LIST* L) {
    int position = sentinelSearch(reg.key, L);
    if (position >= 0) {
        for (position; position < L->nroElements; position++) {
            L->A[position] = L->A[position + 1];
        }
        L->nroElements--;
        return true;
    } else {
        return false;
    }
}

void showList(LIST* L) {
    int i = 0;
    for (i; i < L->nroElements; ++i) { // Iterates and displays all values in the array
        printf("%d, ", L->A[i].key);
    }
    printf("\n\n");
}

int main() {
    LIST LIST;
    initialize(&LIST);

    printf("Value 10 found at position: %d\n\n", sentinelSearch(10, &LIST));
    showList(&LIST);

    RECORD reg;
    reg.key = 7;
    printf("Inserting value: %d\n", reg.key);
    insertOrdered(reg, &LIST);
    showList(&LIST);

    reg.key = 12;
    printf("Deleting value: %d\n", reg.key);
    deleteValue(reg, &LIST);
    showList(&LIST);
    
    return 0;
}
