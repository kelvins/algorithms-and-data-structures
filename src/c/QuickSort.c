#include <stdio.h>
#include <stdbool.h>

void print_array(int array[], int size) {
    printf("[ ");
    for (int index = 0; index < size; ++index) {
        printf("%d", array[index]);
        if (index < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void swap(int array[], int src_index, int dest_index) {
    int temp = array[src_index];
    array[src_index] = array[dest_index];
    array[dest_index] = temp;
}

int lomuto_partition(int array[], int low, int high) {
    int pivot = array[high];
    int index = low;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            swap(array, index, j);
            ++index;
        }
    }
    swap(array, index, high);
    return index;
}

void quicksort_lomuto(int array[], int low, int high) {
    if (low < high) {
        int pivot = lomuto_partition(array, low, high);
        quicksort_lomuto(array, low, pivot - 1);
        quicksort_lomuto(array, pivot + 1, high);
    }
}

int hoare_partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            ++i;
        } while (array[i] < pivot);

        do {
            --j;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }
        swap(array, i, j);
    }
}

void quicksort_hoare(int array[], int low, int high) {
    if (low < high) {
        int pivot = hoare_partition(array, low, high);
        quicksort_hoare(array, low, pivot);
        quicksort_hoare(array, pivot + 1, high);
    }
}

int main() {
    int example_lomuto[] = {5, 3, 1, 4, 2};
    int example_hoare[] = {5, 3, 1, 4, 2};
    int size = 5;

    printf("lomuto quicksort partition:\n");
    print_array(example_lomuto, size);
    quicksort_lomuto(example_lomuto, 0, size - 1);
    print_array(example_lomuto, size);

    printf("hoare quicksort partition:\n");
    print_array(example_hoare, size);
    quicksort_hoare(example_hoare, 0, size - 1);
    print_array(example_hoare, size);
    return 0;
}


//  In english 

// Function to print the contents of an array
// void print_array(int array[], int size) {
//     printf("[ ");
//     for (int index = 0; index < size; ++index) {
//         printf("%d", array[index]);
//         if (index < size - 1) {
//             printf(", ");
//         }
//     }
//     printf(" ]\n");
// }

// // Function to swap two elements in the array
// void swap(int array[], int src_index, int dest_index) {
//     int temp = array[src_index];
//     array[src_index] = array[dest_index];
//     array[dest_index] = temp;
// }

// // Lomuto partition scheme
// int lomuto_partition(int array[], int low, int high) {
//     int pivot = array[high]; // Choosing the last element as the pivot
//     int index = low; // Index of the smaller element

//     // Rearranging the array based on the pivot
//     for (int j = low; j < high; ++j) {
//         if (array[j] < pivot) { // If the current element is less than the pivot
//             swap(array, index, j); // Swap it with the index
//             ++index; // Move the index forward
//         }
//     }
//     swap(array, index, high); // Place the pivot in the correct position
//     return index; // Return the index of the pivot
// }

// // Quick Sort using the Lomuto partition scheme
// void quicksort_lomuto(int array[], int low, int high) {
//     if (low < high) { // Base case for recursion
//         int pivot = lomuto_partition(array, low, high); // Partitioning the array
//         quicksort_lomuto(array, low, pivot - 1); // Recursively sort the left half
//         quicksort_lomuto(array, pivot + 1, high); // Recursively sort the right half
//     }
// }

// // Hoare partition scheme
// int hoare_partition(int array[], int low, int high) {
//     int pivot = array[low]; // Choosing the first element as the pivot
//     int i = low - 1; // Left index
//     int j = high + 1; // Right index

//     while (true) {
//         // Increment i until an element greater than or equal to the pivot is found
//         do {
//             ++i;
//         } while (array[i] < pivot);

//         // Decrement j until an element less than or equal to the pivot is found
//         do {
//             --j;
//         } while (array[j] > pivot);

//         // If the indices cross, return the j index
//         if (i >= j) {
//             return j;
//         }
//         swap(array, i, j); // Swap elements at i and j
//     }
// }

// // Quick Sort using the Hoare partition scheme
// void quicksort_hoare(int array[], int low, int high) {
//     if (low < high) { // Base case for recursion
//         int pivot = hoare_partition(array, low, high); // Partitioning the array
//         quicksort_hoare(array, low, pivot); // Recursively sort the left half
//         quicksort_hoare(array, pivot + 1, high); // Recursively sort the right half
//     }
// }

// int main() {
//     int example_lomuto[] = {5, 3, 1, 4, 2}; // Example array for Lomuto
//     int example_hoare[] = {5, 3, 1, 4, 2}; // Example array for Hoare
//     int size = 5; // Size of the arrays

//     // Using the Lomuto partition scheme
//     printf("Lomuto quicksort partition:\n");
//     print_array(example_lomuto, size); // Print the original array
//     quicksort_lomuto(example_lomuto, 0, size - 1); // Perform Quick Sort
//     print_array(example_lomuto, size); // Print the sorted array

//     // Using the Hoare partition scheme
//     printf("Hoare quicksort partition:\n");
//     print_array(example_hoare, size); // Print the original array
//     quicksort_hoare(example_hoare, 0, size - 1); // Perform Quick Sort
//     print_array(example_hoare, size); // Print the sorted array

//     return 0; // End of the program
// }
