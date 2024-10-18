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


// In english 

// Function for sequential search in an array
// int sequentialSearch(int array[], int size, int target) {
//     for (int i = 0; i < size; i++) {
//         if (array[i] == target) {
//             return i; // Return the index if the target is found
//         }
//     }
//     return -1; // Return -1 if the target is not found    
// }

// int main() {
//     int a[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Example array
//     int n = sizeof(a) / sizeof(a[0]); // Calculate the number of elements in the array
//     printf("Value %d found at index %d\n", 3, sequentialSearch(a, n, 3));
//     printf("Value %d found at index %d\n", 9, sequentialSearch(a, n, 9));
//     return 0;
// }
