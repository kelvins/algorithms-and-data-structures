import functools
import time


def fib_iterativa(n):
    """Fibonnaci iterativa."""
    last = 0
    curr = 1
    for _ in range(0, n):
        last, curr = curr, curr + last
    return last


def fib_recursiva(n):
    """Fibonnaci recursiva."""
    if n < 2:
        return n
    return fib_recursiva(n-1) + fib_recursiva(n-2)


@functools.lru_cache(maxsize=None)
def fib_recursiva_com_cache(n):
    """Fibonacci recursiva com cache."""
    if n < 2:
        return n
    return fib_recursiva_com_cache(n-1) + fib_recursiva_com_cache(n-2)


def run_fibonacci(name, func, n=35):
    start_time = time.time()
    result = func(n)
    diff_time = time.time() - start_time
    print('Fibonacci', name, ':', result, ':', '%.8f' % diff_time, 'segundos')


if __name__ == "__main__":
    run_fibonacci('Iterativa', fib_iterativa)
    run_fibonacci('Recursiva', fib_recursiva)
    run_fibonacci('Recursiva com Cache', fib_recursiva_com_cache)
