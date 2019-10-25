def busca_sequencial(valor, vetor)
  # Procura o valor no vetor sequencialmente
  # Se encontrar retorna o índice, senão -1
  vetor.each_with_index do |elemento, indice|
    return indice if elemento.equal?(valor)
  end
  return -1
end

# Teste Manual
vetor = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
puts busca_sequencial(98, vetor)

# Teste Automatizado
require 'minitest/autorun'

class Test < Minitest::Test
  def test_busca_sequencial_quando_nao_encontra_o_valor
    assert_equal busca_sequencial(5, []), -1
  end

  def test_busca_sequencial_quando_encontra_os_valores
    vetor = [1, 4, 5, 2, 42, 34, 54, 98, 89, 78, 67]
    vetor.each_with_index do |elemento, indice|
      assert_equal busca_sequencial(elemento, vetor), indice
    end
  end
end
