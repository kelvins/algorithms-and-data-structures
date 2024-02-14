# Define a Fibonacci module
defmodule Fib do

  # Function to calculate nth Fibonacci number
  def fibonacci(n) when n >= 0 do
  
    # Initialize starting values  
    last = 0
    curr = 1

    # Use Enum.reduce as a loop from 0 to n-1
    Enum.reduce(0..(n-1), {last, curr}, fn _, {last, curr} ->
      
      # Update last and curr, returning as a tuple
      {curr, curr + last}  
    end)

    # Return the last value after reducing
    |> elem(0) 
  end
end

# Print 10th Fibonacci number  
IO.puts(Fib.fibonacci(10))