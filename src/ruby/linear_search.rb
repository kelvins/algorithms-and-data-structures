# frozen_string_literal: true

def busca_sequencial(value, array)
  # Search for the value sequentially in the array
  # Return its index if found, or -1 otherwise
  array.each_with_index do |element, index|
    return index if element.equal?(value)
  end
  -1
end

array = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts busca_sequencial(98, array)
