public class Palindromo {
  public static void main(String[] args) {
    String word, palavraInvertida = "";
    word = "A grama é amarga";

    for (int i = word.length() - 1; i >= 0; i--) {
      palavraInvertida += word.toLowerCase().charAt(i);
    }

    if (word.replace(" ", "").toLowerCase().equals(palavraInvertida.replace(" ", "")))
      System.out.println("word é um palindromo!");
    else System.out.println("word não é um palindromo!");
  }
}
