/*
Calculo de Pi em C
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





/*
Pi Calculation in C using the Leibniz series
*/

// float calculate_pi_leibniz(int num_terms)
// {
//     float denominator = 1.0f;
//     float sign = 1.0f;
//     float pi = 0.0f;
//     for (int i = 0; i < num_terms; i++)
//     {
//         pi += sign * (4.0 / denominator);
//         denominator += 2.0;
//         sign = sign * -1.0;
//     }
//     return pi;
// }

// int main()
// {
//     int term_counts[4] = {10, 1000, 100000, 10000000};
//     for (int n = 0; n < 4; n++)
//         printf("PI with %i terms: %f\n", term_counts[n], calculate_pi_leibniz(term_counts[n]));

//     return 0;
// }
