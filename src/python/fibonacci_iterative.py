"""
Iterative Fibonacci Algorithm

The lib "time" was used to mark the time of
execution of algorithms in seconds
"""

import functools
import time


def fibonacci(number):
    """Fibonacci iterativa."""
    last = 0
    curr = 1
    for _ in range(0, number):
        last, curr = curr, curr + last
    return last


def main(name, func, number=35):
    """
    Run iterative algorithm and show its execution time
    """
    start_time = time.time()
    result = func(number)
    diff_time = time.time() - start_time
    print("Fibonacci", name, ":", result, ":", "%.8f" % diff_time, "seconds")


if __name__ == "__main__":
    main("Iterative", fibonacci)
