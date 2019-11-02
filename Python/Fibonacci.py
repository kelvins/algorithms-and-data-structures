import functools


def fib_iterativo(n):
    """Fibonnaci iterativo."""
    last = 0
    curr = 1
    for _ in range(0, n):
        last, curr = curr, curr + last
    return last


def fib_recursivo(n):
    """Fibonnaci recursivo."""
    if n < 2:
        return n
    return fib_recursivo(n-1) + fib_recursivo(n-2)


@functools.lru_cache(maxsize=None)
def fib_recursivo_com_cache(n):
    """Fibonacci recursivo com cache."""
    if n < 2:
        return n
    return fib_recursivo_com_cache(n-1) + fib_recursivo_com_cache(n-2)


if __name__ == "__main__":
    print(fib_iterativo(15))
    print(fib_recursivo(15))
    print(fib_recursivo_com_cache(15))
