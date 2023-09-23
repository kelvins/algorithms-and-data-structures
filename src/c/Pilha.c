#include <stdio.h>
#include <stdbool.h> // Include for the 'bool' data type

#define MAX 10
#define ERRO -1

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX + 1]; // The '+1' accounts for the sentinel element
    int nroRegistros;
} PILHA;

// Function to initialize the stack
int inicializa(PILHA* p) {
    p->nroRegistros = 0;
    int i = 0;
    for (i; i < MAX - 2; i++) { // Fills the stack (for testing purposes)
        p->A[i].chave = i * 2; // It's an array of REGISTRO (similar to a class), which could have more fields, so we set A[i].chave to insert the value in the 'chave' field
    }
    p->nroRegistros = i;
}

// Function to insert an element into the stack
bool inserePilha(int valor, PILHA* p) {
    if (p->nroRegistros < MAX) {
        p->A[p->nroRegistros].chave = valor;
        p->nroRegistros++;
        return true;
    } else {
        return false; // Stack is full
    }
}

// Function to remove an element from the stack
bool removePilha(PILHA* p) {
    if (p->nroRegistros > 0) {
        p->nroRegistros--;
        return true;
    } else {
        return false; // Stack is empty
    }
}

// Function to display the stack
void mostraPilha(PILHA* p) {
    int i = p->nroRegistros - 1;
    printf("\nPilha:\n");
    for (i; i >= 0; i--) {
        printf("%d = [ %d ]\n", i, p->A[i].chave);
    }
    printf("------------------\n");
}

// Function to search for an element in the stack
int buscaPilha(int chave, PILHA* p) {
    p->A[p->nroRegistros].chave = chave;
    int aux = 0;
    while (p->A[aux].chave != chave) {
        aux++;
    }
    if (aux == p->nroRegistros) {
        return ERRO; // Element not found
    }
    return aux;
}

int main() {
    PILHA vPilha;
    inicializa(&vPilha);

    mostraPilha(&vPilha);
    if (inserePilha(10, &vPilha)) {
        printf("Inserido com sucesso");
    } else {
        printf("Pilha cheia");
    }

    mostraPilha(&vPilha);
    removePilha(&vPilha);
    mostraPilha(&vPilha);

    int aux = buscaPilha(8, &vPilha);
    if (aux != -1) {
        printf("Valor 8 encontrado na posicao %d da pilha\n", aux);
    } else {
        printf("Valor nao encontrado\n");
    }

    return 0;
}
