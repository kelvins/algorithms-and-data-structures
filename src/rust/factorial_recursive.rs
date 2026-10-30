/*
    Contributors
        - Heitor582
        - Dromedario de Chapéu

    A factorial multiplies all positive integers from 1 through the input.

    Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
*/

// To calculate a factorial recursively, return
// the value multiplied by the function called with value - 1.
fn factorial(value: u128) -> u128 {
    // To avoid multiplying by 0, return 1 when the input is 0 or 1,
    // so the final result is not zeroed out.
    match value {
        0 | 1 => 1,
        2.. => value * (factorial(value - 1)),
    }
}

fn main() {
    println!("{}", factorial(21));
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test_factorial() {
        assert_eq!(factorial(0), 1);
        assert_eq!(factorial(1), 1);
        assert_eq!(factorial(10), 3628800);
    }
}
