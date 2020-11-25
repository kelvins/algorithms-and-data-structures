function is_palindrome(string) {
  string = string.toLowerCase().replace(/\s/g, "");

  const reversedString = string
    .split("")
    .reverse()
    .join("")
    .toLowerCase()
    .replace(/\s/g, "");

  if (string.length <= 1) true;

  return string == reversedString;
}

function main() {
  console.log(is_palindrome(""));
  console.log(is_palindrome("a"));
  console.log(is_palindrome("abba"));
  console.log(is_palindrome("abbas"));
  console.log(is_palindrome("tattarrattat"));
  console.log(is_palindrome("Was it a palindrome?"));
  console.log(is_palindrome("No lemon, no melon"));
}

main();
