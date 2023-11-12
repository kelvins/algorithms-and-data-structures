#include <iostream>
using namespace std;

float pi = 0.0;
float denominator = 1.0;
float operation = 1.0;

float pi_calculator(int terms)
{
    for (int i = 0; i < terms; i++)
    {
        pi += operation * (4.0 / denominator);
        denominator += 2.0;
        operation *= -1.0;
    }
    return pi;
}

int main()
{
    float result = pi_calculator(100000);
    cout << result;
}
