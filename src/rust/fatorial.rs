/*
    Contribuidores
        - Dromedario de Chapéu

    Fatorial é uma função matematica que consistem em realizar
	a multiplicação de todos os antecessores de um numero.

	Ex: 5! = 5 * 4 * 3 * 2 * 1 = 120 
*/

// A diferença desta implementação para a com recursão é 
// que nesta versão o retorno, é feito utilizado interadores.
fn fatorial(valor: u128) -> u128 {
    let total = match valor {
        0  => 1,
        // Product faz a multiplicação de todos os valores em um array
        1.. => (1..valor+1).product(),
    };    
    return total
}

fn main() {
    println!("{}", fatorial(21));
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn teste_fatorial() {
        assert_eq!(fatorial(0), 1);
        assert_eq!(fatorial(1), 1);
        assert_eq!(fatorial(10), 3628800);
    }
}