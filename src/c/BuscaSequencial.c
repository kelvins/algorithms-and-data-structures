#include <stdio.h>

int buscaSequencial(char vetor[], int tamanho, char buscado  ) {
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] == buscado)
        {
            printf("Encontrado na posição %d\n", i);
        }
    }
    return -1;    
}

int main(){
    char a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    buscaSequencial(a, 8, 3);
    buscaSequencial(a, 8, 9);
}