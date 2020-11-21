require "test/unit/assertions"
include Test::Unit::Assertions

# Retorna o índice do elemento. Se não existir, retorna -1.

def busca_sequencial_recursiva(lista, valor, index=0)
    if lista[index] == valor
        return index
    elsif index == lista.size
        return -1
    else
        index +=1
        busca_sequencial_recursiva(lista, valor, index)
    end
end

assert_equal busca_sequencial_recursiva([1, 2, 3, 4, 5], 1, index=0), 0
assert_equal busca_sequencial_recursiva(["a", "b", "c"], 1, index=0), -1
assert_equal busca_sequencial_recursiva([10, 9, 7, 2, 4, 5, 6, 99, 11, 4], 7, index=0), 2