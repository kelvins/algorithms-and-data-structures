require 'minitest/autorun'

class ExponenciacaoTest < Minitest::Test
  def test_exponenciacao
    assert_equal exponenciacao(5, 2), 25
    assert_equal exponenciacao(5, 5), 3125
  end
end
