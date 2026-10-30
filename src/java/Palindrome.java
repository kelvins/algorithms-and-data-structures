public class Palindromo {
  public static void main(String[] args) {
    String word, reversedWord = "";
    word = "A grama é amarga";

    for (int i = word.length() - 1; i >= 0; i--) {
      reversedWord += word.toLowerCase().charAt(i);
    }

    if (word.replace(" ", "").toLowerCase().equals(reversedWord.replace(" ", "")))
      System.out.println("The word is a palindrome!");
    else System.out.println("The word is not a palindrome!");
  }
}
