public class factorial {

  public static void main(String[] args) {
    System.out.println("factorial de 7 : " + factorial(7));
  }

  public static int factorial(int x) {
    int total = 1;
    for (int i = 2; i < x + 1; i++) {
      total = total * i;
    }
    return total;
  }
}
