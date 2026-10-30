/*
    Contributors
        - Dromedario de Chapéu

    A factorial multiplies all positive integers from 1 through the input.

    Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
*/

// The difference between this implementation and the recursive one is
// that this version uses an iterator to produce the result.
fn factorial(value: u128) -> u128 {
    let total = match value {
        0 => 1,
        // Product multiplies all values in an array.
        1.. => (1..value + 1).product(),
    };
    return total;
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
