
def Exponenciacao(base, expoente):
    result = base
    for _ in xrange(0, expoente-1):
        result *= base
    return result

print Exponenciacao(5, 2)
print Exponenciacao(5, 5)