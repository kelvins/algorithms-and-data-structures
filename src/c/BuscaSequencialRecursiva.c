#include <stdio.h>

int buscaSequencialRecursiva(int vetor[], int i, int buscado, int size) {
    
    if (i == size)
    {
        return -1;
    } 
    else if (vetor[i] == buscado)
    {
        return i;
    }
    else
    {
        return buscaSequencialRecursiva(vetor, i+1, buscado, size);
    }
}

int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t n = sizeof(vetor) / sizeof(vetor[0]);
    printf("Valor %d no índice %d\n", 1, buscaSequencialRecursiva(vetor, 0, 1, n));
    printf("Valor %d no índice %d\n", 10, buscaSequencialRecursiva(vetor, 0, 10, n));
}
