# frozen_string_literal: true

def fatorial(number)
  aux = 1
  (2..number).each do |x|
    aux *= x
  end
  aux
end

def fatorial_recursiva(number)
  return 1 if number <= 1

  n * fatorial_recursiva(number - 1)
end

puts fatorial(5)
puts fatorial_recursiva(5)
