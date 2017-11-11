
def fibonacci(n)
    last = 0
    curr = 1
    for _ in 0..n-1
        swap = curr
        curr += last
        last = swap
    end
    return last
end

def fibonacci_recursiva(n)
    if n <= 0
        return 0
    elsif n == 1
        return 1
    else
        return fibonacci(n-1) + fibonacci(n-2)
    end
end

puts fibonacci(12)
puts fibonacci_recursiva(12)
