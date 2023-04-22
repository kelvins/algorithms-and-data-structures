# frozen_string_literal: true

def fatorial(n)
  aux = 1
  (2..n).each do |x|
    aux *= x
  end
  aux
end

def fatorial_recursiva(n)
  return 1 if n <= 1

  n * fatorial_recursiva(n - 1)
end

puts fatorial(5)
puts fatorial_recursiva(5)
