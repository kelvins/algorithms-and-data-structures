public class Fibonacci {

  public static void main(String[] args) {
    System.out.println("Fib(16) : " + fibonacci(16));
  }

  public static int fibonacci(int x) {
    if (x <= 1) return 1;
    else return fibonacci(x - 1) + fibonacci(x - 2);
  }
}
