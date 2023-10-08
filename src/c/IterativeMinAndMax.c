#include <stdio.h>

int main() {
    int array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int min = array[0];
    int max = array[0];

    for (int i = 1; i < 8; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("min: %d\n", min);
    printf("max: %d\n", max);
    return 0;
}
