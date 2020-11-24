#include <stdio.h>

int buscaSequencialRec(char vetor[], int i, char buscado, int size) {
    if (vetor[i] == buscado)
    {
        printf("Encontrado na posição %d\n", i);
    } 
    else if (i == size)
    {
        return -1;
    }
    else
    {
        buscaSequencialRec(vetor, i+1, buscado, size);
    }
    return 0;
}

int main(){
    char a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    buscaSequencialRec(a, 0, 1, 8);
    buscaSequencialRec(a, 0, 10, 8);
}