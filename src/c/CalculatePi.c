/*

https://github.com/DantasB
*/

#include <stdio.h>

float leibniz_pi_calculation(int number)
{
    float denominador = 1.0f;
    float operacao = 1.0f;
    float pi = 0.0f;
    for (int i = 0; i < number; i++)
    {
        pi += operacao * (4.0 / denominador);
        denominador += 2.0;
        operacao = operacao * -1.0;
    }
    return pi;
}

int main()
{
    int n_terms[4] = {10, 1000, 100000, 10000000};
    for (int n = 0; n < 4; n++)
        printf("PI (%i): {%f}\n", n, leibniz_pi_calculation(n_terms[n]));

    return 0;
}