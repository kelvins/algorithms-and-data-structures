#include <stdio.h>

int buscaSequencialRecursiva(int vetor[], int i, int buscado) {
    size_t n = sizeof(vetor) / sizeof(vetor[0]);
    if (vetor[i] == buscado)
    {
        return i;
    } 
    else if (i == n)
    {
        return -1;
    }
    else
    {
        buscaSequencialRecursiva(vetor, i+1, buscado);
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Valor %d no índice %d\n", 1, buscaSequencialRecursiva(a, 0, 1));
    buscaSequencialRecursiva(a, 0, 10);
}