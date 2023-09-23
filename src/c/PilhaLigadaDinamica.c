#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include for the 'bool' data type

#define ERRO -1

typedef int TIPOCHAVE;

typedef struct AUX {
    TIPOCHAVE chave;
    struct AUX* prox;
} *PILHA;

PILHA CREATE(TIPOCHAVE ch) {
    PILHA novaPilha = (PILHA)malloc(sizeof(PILHA));
    novaPilha->chave = ch;
    novaPilha->prox = NULL;
    return novaPilha;
}

PILHA PUSH(TIPOCHAVE ch, PILHA pi) {
    PILHA novo = CREATE(ch);
    novo->prox = pi;
    return novo;
}

PILHA POP(PILHA pi) {
    PILHA sub = pi->prox;
    free(pi);
    return sub;
}

void SHOW(PILHA pi) {
    printf("PILHA:\n");
    while (pi != NULL) {
        printf("[ %d ]\n", pi->chave);
        pi = pi->prox;
    }
}

bool SEARCH(TIPOCHAVE ch, PILHA pi) {
    bool vAchou = false;
    while (pi != NULL) {
        if (pi->chave == ch)
            vAchou = true;
        pi = pi->prox;
    }
    return vAchou;
}

int main() {
    PILHA vPilha = NULL; // Initialize the stack pointer as NULL

    vPilha = PUSH(1, vPilha);
    vPilha = PUSH(2, vPilha);
    vPilha = PUSH(3, vPilha);
    vPilha = PUSH(4, vPilha);
    vPilha = PUSH(5, vPilha);
    vPilha = PUSH(6, vPilha);

    SHOW(vPilha);

    vPilha = POP(vPilha);
    vPilha = POP(vPilha);

    SHOW(vPilha);

    if (SEARCH(6, vPilha))
        printf("\nAchou\n");
    else
        printf("\nNão achou\n");

    return 0;
}
