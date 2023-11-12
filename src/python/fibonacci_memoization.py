import functools
import time


@functools.lru_cache(maxsize=None)
def fibonacci(number):
    """Fibonacci recursiva com cache."""
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
    main("Fibonacci Memoization:", fibonacci)
