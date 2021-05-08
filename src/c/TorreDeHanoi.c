#include <stdio.h>

void hanoi(int pino0, int pino2, int pino1, int discos)
{
    if (discos == 1)
        printf("Move de %i para %i\n", pino0, pino2);

    else
    {
        hanoi(pino0, pino1, pino2, discos - 1);
        hanoi(pino0, pino2, pino1, 1);
        hanoi(pino1, pino2, pino0, discos - 1);
    }
}

int main()
{
    hanoi(0, 2, 1, 3);
    return 0;
}
