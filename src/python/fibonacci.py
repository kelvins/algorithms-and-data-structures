"""
Implementaço de vários algoritmos Fibonacci

A lib "time" foi utilizada para marcar o tempo de
execução dos algoritmos em segundos
"""

import functools
import time


def fib_iterativa(number):
    """Fibonacci iterativa."""
    last = 0
    curr = 1
    for _ in range(0, number):
        last, curr = curr, curr + last
    return last


def fib_recursiva(number):
    """Fibonnaci recursiva."""
    if number < 2:
        return number
    return fib_recursiva(number - 1) + fib_recursiva(number - 2)


@functools.lru_cache(maxsize=None)
def fib_recursiva_com_cache(number):
    """Fibonacci recursiva com cache."""
    if number < 2:
        return number
    return fib_recursiva_com_cache(number - 1) + fib_recursiva_com_cache(
        number - 2
    )


def run_fibonacci(name, func, number=35):
    """
    Roda o algoritmo e mostra o tempo de execução dele
    """
    start_time = time.time()
    result = func(number)
    diff_time = time.time() - start_time
    print('Fibonacci', name, ':', result, ':', '%.8f' % diff_time, 'segundos')


if __name__ == "__main__":
    run_fibonacci('Iterativa', fib_iterativa)
    run_fibonacci('Recursiva', fib_recursiva)
    run_fibonacci('Recursiva com Cache', fib_recursiva_com_cache)
