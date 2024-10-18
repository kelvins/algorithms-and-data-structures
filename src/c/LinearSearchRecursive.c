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

//  In english 


// Recursive function for sequential search in an array
// int recursiveSequentialSearch(int array[], int i, int target, int size) {
//     // Base case: if the index reaches the size of the array
//     if (i == size) {
//         return -1; // Target not found
//     } 
//     // If the current element matches the target
//     else if (array[i] == target) {
//         return i; // Return the index
//     } 
//     // Recursively call the function for the next index
//     else {
//         return recursiveSequentialSearch(array, i + 1, target, size);
//     }
// }

// int main() {
//     int array[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Example array
//     size_t n = sizeof(array) / sizeof(array[0]); // Calculate the number of elements in the array
//     printf("Value %d found at index %d\n", 1, recursiveSequentialSearch(array, 0, 1, n));
//     printf("Value %d found at index %d\n", 10, recursiveSequentialSearch(array, 0, 10, n));
//     return 0;
// }
