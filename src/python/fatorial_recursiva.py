""" Algoritmo de fatorial implementado com recursão """
"""Factorial Algorithm Implemented with Recursion"""

def recursive_factorial(number):
    """
    Implementation of a factorial algorithm using recursion.

    Arguments:
        number: int. The number for which you want to calculate the factorial.

    Returns the result of the operation.
    """
    if number == 1:
        return 1

    return number * recursive_factorial(number - 1)

print(recursive_factorial(5))
