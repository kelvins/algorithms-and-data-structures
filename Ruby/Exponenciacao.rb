
def exponenciacao(base, expoente)
    result = base
    for _ in 0..expoente-2
        result *= base
    end
    return result
end

puts exponenciacao(5, 2)
puts exponenciacao(5, 5)