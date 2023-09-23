/*
*	Example of Queue Implementation in C
*	Kelvin S. do Prado
*/

#include <stdio.h>
#include <stdbool.h> // Added for boolean support

#define MAX 10
#define ERROR -1

typedef int KEY;

typedef struct {
    KEY key;
} RECORD;

typedef struct {
    RECORD A[MAX + 1];
    int numberOfRecords;
} QUEUE;

void initialize(QUEUE* Q) {
    int i = 0;
    for (i; i < MAX - 2; i++) {
        Q->A[i].key = i * 2;
    }
    Q->numberOfRecords = i;
}

void showQueue(QUEUE* Q) {
    int i = 0;
    printf("QUEUE:\n");
    for (i; i < Q->numberOfRecords; i++) {
        printf("[ %d ] ", Q->A[i].key);
    }
    printf("\n\n");
}

bool enqueue(KEY k, QUEUE* Q) {
    if (Q->numberOfRecords >= MAX)
        return false;
    Q->A[Q->numberOfRecords].key = k;
    Q->numberOfRecords++;
    return true;
}

bool dequeue(QUEUE* Q) {
    if (Q->numberOfRecords <= 0)
        return false;
    int i = 1;
    for (i; i < Q->numberOfRecords; i++) {
        Q->A[i - 1].key = Q->A[i].key;
    }
    Q->numberOfRecords--;
    return true;
}

int searchQueue(KEY k, QUEUE* Q) {
    Q->A[Q->numberOfRecords].key = k; // Place k in the last position for sentinel search
    int i = 0;
    while (Q->A[i].key != k)
        i++;
    if (i >= Q->numberOfRecords)
        return ERROR;
    return i;
}

int main() {
    QUEUE queue;
    initialize(&queue);
    showQueue(&queue);

    enqueue(15, &queue);
    showQueue(&queue);

    dequeue(&queue);
    showQueue(&queue);

    printf("The searched key is located at position %d in the queue\n\n", searchQueue(8, &queue));
    return 0;
}
