""" Algoritmo de exponenciação """
"""Exponentiation Algorithm"""

def exponentiation(base, exponent):
    """
    Implementation of an exponentiation algorithm.

    Arguments:
        base: int. Base of the operation.
        exponent: int. Exponent of the operation.

    Returns the result of the exponentiation operation.
    """
    result = base
    for _ in range(0, exponent - 1):
        result *= base
    return result

print(exponentiation(5, 2))
print(exponentiation(5, 5))
