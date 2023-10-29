#include <stdio.h>

int buscaSequencial(int vetor[], int size, int buscado) {
    for (int i = 0; i < size; i++)
    {
        if (vetor[i] == buscado)
        {
            return i;
        }
    }
    return -1;    
}

int main(){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Valor %d no índice %d\n", 3, buscaSequencial(a, n, 3));
    printf("Valor %d no índice %d\n", 9, buscaSequencial(a, n, 9));
}

