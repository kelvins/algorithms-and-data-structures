#include <stdio.h>

int buscaSequencial(int vetor[], int buscado) {
    size_t n = sizeof(vetor[0]);
    for (int i = 0; i < n; i++)
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
    buscaSequencial(a, 3);
    buscaSequencial(a, 9);
}