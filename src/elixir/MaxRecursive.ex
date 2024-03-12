defmodule MaxRecursive do
  # Base case: When n is 1, return the first element of the list (head).
  def max_recursive(nums, 1), do: hd(nums)

  # Recursive case: Calculate the maximum recursively.
  def max_recursive(nums, n) do
    aux = max_recursive(nums, n - 1)
    if aux > Enum.at(nums, n - 1) do
      aux
    else
      Enum.at(nums, n - 1)
    end
  end
end

# Example usage
nums = [1, 2, 3, 4, 32, 6, 7, 8, 9, 10]
IO.inspect "nums = #{inspect(nums)}"
IO.inspect "Max = #{MaxRecursive.max_recursive(nums, length(nums))}"
