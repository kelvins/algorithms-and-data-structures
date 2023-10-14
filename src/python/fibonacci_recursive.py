"""
Implementaço de vários algoritmos Fibonacci

A lib "time" foi utilizada para marcar o tempo de
execução dos algoritmos em segundos
"""

import time


def fibonacci(number):
    """Fibonnaci recursiva."""
    if number < 2:
        return number
    return fibonacci(number - 1) + fibonacci(number - 2)


def main(name, func, number=35):
    """
    Roda o algoritmo e mostra o tempo de execução dele
    """
    start_time = time.time()
    result = func(number)
    diff_time = time.time() - start_time
    print("Fibonacci", name, ":", result, ":", "%.8f" % diff_time, "segundos")


if __name__ == "__main__":
    main("Recursiva", fibonacci)
