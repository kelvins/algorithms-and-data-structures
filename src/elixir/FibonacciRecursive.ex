# Define a Fibonacci module
defmodule Fibonacci do
  # Base case: If n is 0 or 1, return n.
  def fibonacci(n) when n <= 1, do: n

  # Recursive case: Calculate the Fibonacci number by summing the results
  # of the previous two Fibonacci numbers.
  def fibonacci(n) do
    fibonacci(n - 1) + fibonacci(n - 2)
  end
end

# Print the Fibonacci number for n = 10.
IO.puts("Fibonacci(n): #{Fibonacci.fibonacci(10)}")