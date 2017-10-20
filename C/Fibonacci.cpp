
#include <iostream>

using namespace std;

int fibonacci(int n)
{
    int last = 0;
    int curr = 1;
    for (int index = 0; index < n; ++index)
    {
        int temp = curr;
        curr += last;
        last = temp;
    }
    return last;
}

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
    cout << fibonacci(12) << endl;
    cout << fibonacciRecursive(12) << endl;
}
