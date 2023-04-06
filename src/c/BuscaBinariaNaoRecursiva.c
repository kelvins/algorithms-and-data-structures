/* Fonte: Feofiloff, Paulo. Algoritmos em Liguagem C.
          Rio de Janeiro: Elservier, 2009.*/

#include <stdio.h>

int BuscaBinariaNaoRecursiva (int elementoASerBuscado, int totalElementosNoVetor, int vetorDeElementos[]) {
    int inicio, meio, fim;
    int contadorVezes = 0;

    inicio = -1;
    fim = totalElementosNoVetor;
    printf("Iniciando a busca binária não recursiva dentro de %d elementos...\n", totalElementosNoVetor);

    while (inicio < fim-1) {
        meio = (inicio + fim) / 2;
        if (vetorDeElementos[meio] < elementoASerBuscado) {
            inicio = meio;
        } else {
            fim = meio;
        }
    }
    return fim;
}

void main() {
    int vetorDeNumeros[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int resultado;

    resultado = BuscaBinariaNaoRecursiva(18, 20, vetorDeNumeros);
    printf("Elemento encotrado: %d\n", resultado);
}

/*
$ gcc -o busca_binaria_nao_recursiva src/c/BuscaBinariaNaoRecursiva.c
$ ./busca_binaria_nao_recursiva
Iniciando a busca binária não recursiva dentro de 20 elementos...
Elemento encotrado: 18
*/