defmodule Factorial do
  # Define a module called Factorial.

  def factorial(n) when n >= 0 do
    # Calculate the factorial using Enum.reduce.
    Enum.reduce(1..n, 1, &(&1 * &2))
  end

  defp format_factorial(i, result) do
    # Format the output string.
    "#{i}! = #{result}"
  end

  def main do
    # Entry point of the program.
    nums = [0, 1, 2, 3, 4, 5]

    Enum.each(nums, fn i ->
      # Iterate through the list of numbers.
      result = factorial(i)
      IO.puts(format_factorial(i, result))
    end)
  end
end

Factorial.main()  # Execute the program.
