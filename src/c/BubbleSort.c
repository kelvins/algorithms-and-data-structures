#include <stdio.h>

// Function to swap two elements in the array
void swap(int array[], int j)
{
    int t = array[j];
    array[j] = array[j + 1];
    array[j + 1] = t;
}

// Bubble Sort algorithm to sort the array in ascending order
void bubble_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array, j);
            }
        }
    }
}

int main()
{
    int array_size = 10; // Array size
    int array[10] = {99, 33, 22, 10, 5, 7, 9, 0, 15, 27}; // Input array

    // Call the bubble_sort function to sort the array
    bubble_sort(array, array_size);

    printf("Sorted list:\n");
    for (int i = 0; i < array_size - 1; i++)
        printf("%d, ", array[i]);

    printf("%d\n", array[array_size - 1]);

    return 0;
}
