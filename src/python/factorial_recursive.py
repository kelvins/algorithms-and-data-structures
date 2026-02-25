"""Recursive factorial algorithm"""


def factorial_recursive(num):
    """
    Implementation of factorial algorithm using recursion

    Arguments:
        num: int. the number of which you want to obtain the factorial.

    Returns the result of the factorial operation
    """
    if num == 1:
        return 1

    return num * factorial_recursive(num - 1)


print(factorial_recursive(5))
