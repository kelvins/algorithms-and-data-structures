""" Iterative factorial algorithm """


def factorial(num):
    """
    Implementation of the factorial algorithm iteratively.

    Arguments:
        num: int. the number of which you want to obtain the factorial.

    Returns the result of the factorial operation
    """
    aux = 1
    for i in range(2, num + 1):
        aux = aux * i
    return aux


if __name__ == "__main__":
    print(factorial(5))
