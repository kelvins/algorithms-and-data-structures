#include<stdio.h>

int BinarySearch(int array[], int size, int value) {
    int start = 0;
    int end = size - 1;
    int middle = end / 2;

    while (start < end && array[middle] != value) {
        // new start
        if (value > array[middle])
            start = middle + 1;

        // new end
        if (value < array[middle])
            end = middle - 1;

        // new middle
        middle = (start + end) / 2;
    }

    if (array[middle] == value)
        return middle;

    return -1;
}

int main() {
    int value;
    int array[] = {1, 5, 10, 12, 18, 22, 87, 90, 112, 129};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Please provide the number you want to value for: ");
    scanf("%d", &value);

    int pos = BinarySearch(array, size, value);

    if (pos != -1)
        printf("Found in position = %d.\nValue = %d\n", pos, array[pos]);
    else
        printf("Not found\n");

    return 0;
}
