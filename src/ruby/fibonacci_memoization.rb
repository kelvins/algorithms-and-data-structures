def fibonacci(n, memo = {})
  if n <= 1
    return 1
  end

  # Check if the result is already memoized
  if memo.key?(n)
    return memo[n]
  end

  # Calculate Fibonacci recursively and store the result in memoization
  result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
  memo[n] = result

  return result
end

n = 16
puts "Fib(#{n}): #{fibonacci(n)}"
