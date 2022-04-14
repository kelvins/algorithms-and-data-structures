#
#   Contribuidores
#       - Dromedário de Chapéu
#

defmodule Fatorial do
    @moduledoc """
        Fatorial é uma operação que consiste em fazer
        a multiplicação de um numero por todos os seus
        antecesorrs.

        Ex: 5! = 5 * 4 * 3 * 2 * 1 = 120
    """

    # Em elixir existe o conceito de pattern matching
    # que permite fazer com que uma função façã X ou Y
    # dependendo do que ela recebe
    def fatorial(1), do: 1 # No caso de fatorial de 1 é retornado 1
    def fatorial(0), do: 1 # Par 0 o mesmo se aplica, para n multiplicar por 0

    # Para fazer o loop do fatorial, apenas fazermos uma recursão com num - 1
    # ate atingir 1 ou 0, que são os valores de parada
    def fatorial(num), do: num * fatorial(num - 1)

end

IO.puts Fatorial.fatorial(3)
