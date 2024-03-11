"""
Recursive Fibonacci Algorithm

The lib "time" was used to mark the time of
execution of algorithms in seconds
"""

import time


def fibonacci(number):
    """
    Recursive Fibonacci
    """

    if number < 2:
        return number
    return fibonacci(number - 1) + fibonacci(number - 2)


def main(name, func, number=35):
    """
    Run the algorithm and show its execution time
    """
    start_time = time.time()
    result = func(number)
    diff_time = time.time() - start_time
    print("Fibonacci", name, ":", result, ":", "%.8f" % diff_time, "seconds")


if __name__ == "__main__":
    main("Recursive", fibonacci)
