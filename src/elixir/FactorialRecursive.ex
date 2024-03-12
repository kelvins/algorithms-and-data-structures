# Define Math module for math utilities
defmodule Math do

  # Recursive factorial function
  def factorial(0), do: 1 # Base case

  def factorial(n) when n > 0 do 
    # Recursive case
    n * factorial(n-1) 
  end

end

# Array of numbers to get factorials for
nums = [0, 1, 2, 3, 4, 5] 

# Loop through the nums array
for i <- nums do

  # Calculate and print factorial 
  IO.puts "#{i}! = #{Math.factorial(i)}" 

end