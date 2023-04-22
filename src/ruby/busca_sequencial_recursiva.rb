# frozen_string_literal: true

require "test/unit/assertions"
include Test::Unit::Assertions

# Retorna o índice do elemento. Se não existir, retorna -1.

def busca_sequencial_recursiva(lista, valor, index = 0)
  if lista[index] == valor
    index
  elsif index == lista.size
    -1
  else
    index += 1
    busca_sequencial_recursiva(lista, valor, index)
  end
end

assert_equal busca_sequencial_recursiva([1, 2, 3, 4, 5], 1), 0
assert_equal busca_sequencial_recursiva(%w[a b c], 1), -1
assert_equal busca_sequencial_recursiva([10, 9, 7, 2, 4, 5, 6, 99, 11, 4], 7), 2
