/*
    Contribuidores
        - Heitor582
        - Dromedario de Chapéu

    Fatorial é uma função matematica que consistem em realizar
    a multiplicação de todos os antecessores de um number.

    Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
*/

// To calculate a factorial recursively, return
// the value multiplied by the function called with value - 1.
fn fatorial(value: u128) -> u128 {
    // To avoid multiplying by 0, return 1 when the input is 0 or 1,
    // so the final result is not zeroed out.
    match value {
        0 | 1 => 1,
        2.. => value * (fatorial(value - 1)),
    }
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
