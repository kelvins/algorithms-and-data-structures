""" Recursive exponentiation algorithm """


def exponentiation_recursive(base, exponent):
    """
    Implementation of an exponentiation algorithm using recursion.

    Arguments:
        base (int): Base of operation
        exponent (int): Exponent of operation

    Returns:
        Returns the result of the exponentiation operation.
    """
    if exponent == 0:
        return 1

    return base * exponentiation_recursive(base, exponent - 1)


if __name__ == "__main__":
    print(exponentiation_recursive(5, 2))
    print(exponentiation_recursive(5, 5))
