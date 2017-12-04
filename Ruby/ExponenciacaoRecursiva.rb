
def exponenciacao(base, expoente)
    if expoente == 0
        return 1
    else
        return base * exponenciacao(base, expoente-1)
    end
end

puts exponenciacao(5, 2)
puts exponenciacao(5, 5)