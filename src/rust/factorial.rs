/*
    Contribuidores
        - Dromedario de Chapéu

    Fatorial é uma função matematica que consistem em realizar
    a multiplicação de todos os antecessores de um numero.

    Ex: 5! = 5 * 4 * 3 * 2 * 1 = 120
*/

// The difference between this implementation and the recursive one is
// that this version uses an iterator to produce the result.
fn fatorial(valor: u128) -> u128 {
    let total = match valor {
        0 => 1,
        // Product multiplies all values in an array.
        1.. => (1..valor + 1).product(),
    };
    return total;
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
