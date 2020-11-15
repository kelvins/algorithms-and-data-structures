fn main() {
    println!("{:?}", palindromo("".to_string()));
    println!("{:?}", palindromo("a".to_string()));
    println!("{:?}", palindromo("abba".to_string()));
    println!("{:?}", palindromo("abbas".to_string()));
    println!("{:?}", palindromo("tattarrattat".to_string()));
    println!("{:?}", palindromo("Was it a palindrome?".to_string()));
    println!("{:?}", palindromo("No lemon, no melon".to_string()));
}
fn palindromo(mut word: String) -> bool {
    word = word.to_lowercase().split_whitespace().collect::<String>();
    let reversed_string: String = word.chars().rev().collect::<String>();
    if word.len() <= 1 {
        return true;
    }
    word == reversed_string
}
