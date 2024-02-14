# Module to calculate an approximation of Pi
defmodule PiApproximation do

  # Function to calculate pi given number of terms
  def calculate_pi(terms) do
  
    # Initialize pi accumulator 
    pi = 0.0 

    # Reduce over 1..terms range
    # Accumulator is a tuple with pi, denominator, and operation
    Enum.reduce(1..terms, {pi, 1.0, 1.0}, fn _, {acc_pi, acc_denom, acc_op} ->
    
      # Calculate new pi value    
      new_pi = acc_pi + acc_op * (4.0 / acc_denom)

      # Return tuple with updated values
      {new_pi, acc_denom + 2.0, -acc_op} 
    end) |> elem(0)
  end

end

# Number of terms to approximate
terms = 100_000  

# Call approximation function
result = PiApproximation.calculate_pi(terms)

# Print result
IO.puts(result)