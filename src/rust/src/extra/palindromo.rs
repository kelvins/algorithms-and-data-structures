use regex::Regex;
pub fn palindromo(mut word: String) -> bool{
  let re = Regex::new(r"\s").unwrap();
  word = word.to_lowercase();
  let reversed_string: String = word.chars().rev().collect::<String>().to_lowercase();
  if word.len() <= 1 {
    return true;
  }
  re.replace_all(Box::leak(word.into_boxed_str()),"") == re.replace_all(Box::leak(reversed_string.into_boxed_str()),"")
}