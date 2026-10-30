class Main {

  public static long exponentiation(long base, long exponent) { // exponentiation recursive
    if (exponent == 0) return 1;
    return (base * exponentiation(base, exponent - 1));
  }

  public static void main(String args[]) {
    System.out.println("5 ^ 3 = " + exponentiation(5, 3));
  }
}
