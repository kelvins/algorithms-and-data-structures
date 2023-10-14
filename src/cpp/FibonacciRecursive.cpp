
#include <iostream>

using namespace std;

int fibonacciRecursive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

int main()
{
    cout << fibonacciRecursive(12) << endl;
}
