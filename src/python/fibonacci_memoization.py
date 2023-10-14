def fibonacci(n, memo={}):
    if n <= 1:
        return 1

    # Check if the result is already memoized
    if n in memo:
        return memo[n]

    # Calculate Fibonacci recursively and store the result in memoization
    result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    memo[n] = result

    return result

n = 16
print(f"Fib({n}): {fibonacci(n)}")
