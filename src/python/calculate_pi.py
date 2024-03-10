""" Calculating PI in Python """


def calculate_pi(number):
    """
    Implementation of a PI calculation algorithm.

    Arguments:
    number: int.

    Returns the value of PI.
    """
    denominator = 1.0
    operation = 1.0
    pi = 0.0
    for _ in range(number):
        pi += operation * (4.0 / denominator)
        denominator += 2.0
        operation *= -1.0
    return pi


if __name__ == "__main__":
    n_terms = [10, 1000, 100000, 10000000]
    for n in n_terms:
        print(f"PI ({n}): {calculate_pi(n)}")
