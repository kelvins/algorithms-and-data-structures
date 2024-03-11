"""
Recursive Fibonacci Algorithm using a Cache
"""

import functools
import time


@functools.lru_cache(maxsize=None)
def fibonacci(number):
    """
    Recursive fibonacci algorithm with cache
    """
    if number < 2:
        return number
    return fibonacci(number - 1) + fibonacci(number - 2)


def main(name, func, number=35):
    """
    Run algorithm and show its execution time
    """
    start_time = time.time()
    result = func(number)
    diff_time = time.time() - start_time
    print("Fibonacci", name, ":", result, ":", "%.8f" % diff_time, "seconds")


if __name__ == "__main__":
    main("Memorization:", fibonacci)
