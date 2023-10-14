# frozen_string_literal: true

def fibonacci(number)
  last = 0
  curr = 1
  (0..number - 1).each do |_|
    swap = curr
    curr += last
    last = swap
  end
  last
end

puts fibonacci(12)
