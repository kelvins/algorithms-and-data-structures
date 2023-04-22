# frozen_string_literal: true

# Fatorial em Ruby
# Carlos Alves
# https://github.com/EuCarlos

def factorial(value)
  aux = 1
  (1..value).each do |i|
    aux *= i
  end

  aux
end

def main
  11.times do |number|
    puts "#{number}! = #{factorial(number)}"
  end
end

main
