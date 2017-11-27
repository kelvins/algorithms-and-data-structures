
def fatorial(n)
    aux = 1
    for x in 2..n
        aux = aux * x
    end
    return aux
end

def fatorial_recursiva(n)
    if n <= 1
        return 1
    else
        return n * fatorial_recursiva(n-1)
    end
end

puts fatorial(5)
puts fatorial_recursiva(5)