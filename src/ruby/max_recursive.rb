# frozen_string_literal: true

# Recursive maximum algorithm in Ruby
# Carlos Alves
# https://github.com/EuCarlos

def max_recursivo(array, maximo, index)
  maximo = array[index] if array[index] > maximo

  maximo = max_recursivo(array, maximo, index + 1) if index < array.length - 1

  maximo
end

list = [19, 32, 43, 58, 12, 28, 98, 19, 12, 10]
print list

puts "\nMaximo recursive: #{max_recursivo(list, list[0], 0)}"
