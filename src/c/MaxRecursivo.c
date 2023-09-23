/*
* Examples of functions to find the maximum number in an array
* All three functions are recursive, but only MaxDC uses divide and conquer.
* Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Maximum using Divide and Conquer
int MaxDC(int *array, int start, int end)
{
    int aux1, aux2;
    int middle = (start + end) / 2;

    if (start == end)
    {
        return array[start];
    }

    aux1 = MaxDC(array, start, middle);
    aux2 = MaxDC(array, middle + 1, end);

    if (aux1 > aux2)
    {
        return aux1;
    }
    else
    {
        return aux2;
    }
}

void max1(int *array, int maximum, int index)
{
    if (array[index] > maximum)
    {
        maximum = array[index];
    }

    if (index < MAX - 1)
    {
        max1(array, maximum, index + 1);
    }
    else
    {
        printf("\n\nMax1: %d\n", maximum);
    }
}

int max2(int array[], int arraySize)
{
    if (arraySize == 1)
    {
        return array[0]; // Only one element
    }
    else
    {
        int x = max2(array, arraySize - 1);

        if (x > array[arraySize - 1])
        {
            return x;
        }
        else
        {
            return array[arraySize - 1];
        }
    }
}

int main()
{
    int array[MAX];

    for (int i = 0; i < MAX; ++i)
    {
        array[i] = (rand() % 90) + 10; // Random numbers between 10 and 99
        printf("%d, ", array[i]);
    }

    max1(array, array[0], 1);

    printf("\nMax2: %d\n", max2(array, MAX));
    printf("\nMaxDC: %d\n\n", MaxDC(array, 0, MAX - 1));

    return 0;
}
