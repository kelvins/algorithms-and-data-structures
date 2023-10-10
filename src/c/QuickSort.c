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