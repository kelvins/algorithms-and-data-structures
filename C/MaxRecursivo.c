/*
* Exemplos de funções para achar maior número de um vetor
* As 3 são recursivas porém apenas a MaxDC utiliza divisão e conquista
* Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Maximo usando Divisão e Conquista
int MaxDC(int *vetor, int inicio, int fim)
{
    int aux1, aux2;
    int meio = ( inicio + fim ) / 2;

    if( inicio == fim )
    {
        return vetor[inicio];
    }

    aux1 = MaxDC(vetor, inicio, meio);
    aux2 = MaxDC(vetor, meio+1, fim);

    if( aux1 > aux2 )
    {
        return aux1;
    }
    else
    {
        return aux2;
    }
}

void max1(int *vetor, int maximo, int indice)
{
    if( vetor[indice] > maximo )
    {
        maximo = vetor[indice];
    }

    if( indice < MAX-1 )
    {
        max1(vetor, maximo, indice+1);
    }
    else
    {
        printf("\n\nMax1: %d\n",maximo);
    }
}

int max2(int vetor[], int tamVetor)
{
    if (tamVetor == 1)
    {
        return vetor[0]; // só tem 1 elemento
    }
    else
    {
        int x = max2(vetor, tamVetor-1);

        if (x > vetor[tamVetor-1])
        {
            return x;
        }
        else
        {
            return vetor[tamVetor-1];
        }
    }
}

int main()
{
    int vetor[MAX];

    for (int i = 0; i < MAX; ++i)
    {
        vetor[i] = (rand() % 90) + 10; // 10 a 99
        printf("%d, ", vetor[i]);
    }

    max1(vetor, vetor[0], 1);

    printf("\nMax2: %d\n", max2(vetor, MAX) );
    printf("\nMaxDC: %d\n\n", MaxDC(vetor, 0, MAX-1) );

    return 0;
}
