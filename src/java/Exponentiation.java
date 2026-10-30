class Main {

  public static long exponentiation(int base, int exponent) {

    int i;
    int result = base;

    for (i = 0; i < exponent - 1; i++) result *= base;

    return result;
  }

  public static void main(String args[]) {
    System.out.println("5 ^ 3 = " + exponentiation(5, 3));
  }
}
