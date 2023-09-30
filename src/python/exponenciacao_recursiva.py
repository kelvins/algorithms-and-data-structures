""" Algoritmo de exponenciação implementado com recursão. """
"""Exponentiation algorithm implemented using recursion."""

def recursive_exponentiation(base, exponent):
    """Implementation of an exponentiation algorithm.

    Args:
        base (int): Base of the operation.
        exponent (int): Exponent of the operation.

    Returns:
        Returns the result of the exponentiation operation.
    """
    if exponent == 0:
        return 1

    return base * recursive_exponentiation(base, exponent - 1)


if __name__ == "__main__":
    print(recursive_exponentiation(5, 2))
    print(recursive_exponentiation(5, 5))
