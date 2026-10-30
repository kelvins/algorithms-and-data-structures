public class factorialRecursiva {

  public static void main(String[] args) {
    System.out.println("factorial de 0 : " + factorial(0));
    System.out.println("factorial de 1 : " + factorial(1));
    System.out.println("factorial de 3 : " + factorial(3));
    System.out.println("factorial de 7 : " + factorial(7));
  }

  public static int factorial(int x) {
    if (x <= 1) return 1;
    else return x * factorial(x - 1);
  }
}
