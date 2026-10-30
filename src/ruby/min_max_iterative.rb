# frozen_string_literal: true

# Iterative minimum and maximum in Ruby
# Carlos Alves
# https://github.com/EuCarlos

def min_max_array(array)
  minimo = array[0]
  maximo = array[0]

  vetor_size = array.length - 1
  (1..vetor_size).each do |i|
    if array[i] < minimo
      minimo = array[i]
    elsif array[i] > maximo
      maximo = array[i]
    end
  end

  puts "Minimo: #{minimo}"
  puts "Maximo: #{maximo}"
end

list = [2, 94, 83, 10, 0, 2, 48, 1, 24]
min_max_array(list)
