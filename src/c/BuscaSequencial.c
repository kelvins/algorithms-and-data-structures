#include <stdio.h>

int sequentialSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Return the index where the target value was found
        }
    }
    return -1; // Return -1 if the target value was not found in the array
}

int main(){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Value %d found at index %d\n", 3, sequentialSearch(a, n, 3));
    printf("Value %d found at index %d\n", 9, sequentialSearch(a, n, 9));
}
