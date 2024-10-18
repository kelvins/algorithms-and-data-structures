#include <stdio.h>
#include <stdlib.h>

// CountingSort - Ordenação por Contagem - Matheus Martins Batista - Universidade Federal de Itajuba - 2021

// Necessário encontrar o maior elemento para alocar o vetor auxiliar de contagem
int findMax (int *arr, int tam) {
    int max = arr[0];

    for (int i = 1; i < tam; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Ordena os valores presentes em A e armazena em B
void countingSort(int *arrA, int *arrB, int tam) {
    // Vetor de contagem terá a frequência que um número aparece no vetor
    // deve-se setar 0 para todos os elementos ou usar calloc
    int max = findMax(arrA, tam);
    int* count = calloc(max + 1, sizeof(int));

    // Frequência que determinado valor aparece no vetor
    for (int i = 0; i < tam; i++) {
        count[arrA[i]]++;
    }

    // Acumulativo da frequência dos valores menores que um elemento i do vetor original (A)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Percorrer o vetor original com início no último elemento, subtituindo os indices nos elementos do vetor count e decrescendo a cada atribuição
    for (int i = tam - 1; i >= 0; i--) {
        arrB[count[arrA[i]] - 1] = arrA[i];
        count[arrA[i]]--;
    }
}

int main() {
    int *arrA, *arrB;
    int tam = 10;
    arrA = malloc(tam * sizeof(int));
    arrB = calloc(tam, sizeof(int));

    // Popular vetor A
    srand(48+tam);
    for(int j = 0; j < tam; j++) arrA[j] = rand()%100;

    countingSort(arrA, arrB, tam);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arrB[i]);
    }

    return 0;
}


//  In english

/*
*
*	CountingSort - Counting Sort Algorithm
*	Matheus Martins Batista - Universidade Federal de Itajuba - 2021
*
*/

// Function to find the maximum element in the array
// int findMaxValue(int *array, int size) {
//     int maxValue = array[0];

//     // Iterate through the array to find the maximum value
//     for (int i = 1; i < size; i++) {
//         if (array[i] > maxValue) {
//             maxValue = array[i]; // Update maxValue if current element is greater
//         }
//     }

//     return maxValue; // Return the maximum value found
// }

// // Function to perform counting sort on arrayA and store the result in arrayB
// void countingSort(int *arrayA, int *arrayB, int size) {
//     // Find the maximum value in arrayA to determine the size of the count array
//     int maxValue = findMaxValue(arrayA, size);
    
//     // Allocate memory for the count array and initialize it to 0
//     int* countArray = calloc(maxValue + 1, sizeof(int));

//     // Count the frequency of each element in arrayA
//     for (int i = 0; i < size; i++) {
//         countArray[arrayA[i]]++;
//     }

//     // Compute the cumulative frequency
//     for (int i = 1; i <= maxValue; i++) {
//         countArray[i] += countArray[i - 1];
//     }

//     // Build the output array arrayB in sorted order
//     for (int i = size - 1; i >= 0; i--) {
//         arrayB[countArray[arrayA[i]] - 1] = arrayA[i];
//         countArray[arrayA[i]]--; // Decrement the count for the current element
//     }

//     // Free the allocated memory for the count array
//     free(countArray);
// }

// int main() {
//     int *arrayA, *arrayB; // Pointers for the input and output arrays
//     int size = 10; // Size of the array
//     arrayA = malloc(size * sizeof(int)); // Allocate memory for the input array
//     arrayB = calloc(size, sizeof(int)); // Allocate memory for the output array

//     // Populate arrayA with random values
//     srand(48 + size);
//     for (int j = 0; j < size; j++) {
//         arrayA[j] = rand() % 100; // Random values between 0 and 99
//     }

//     // Perform counting sort
//     countingSort(arrayA, arrayB, size);

//     // Print the sorted output
//     printf("Sorted array: ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arrayB[i]);
//     }
//     printf("\n");

//     // Free the allocated memory for the input and output arrays
//     free(arrayA);
//     free(arrayB);

//     return 0;
// }
