public class Fibonacci {

  public static void main(String[] args) {
    System.out.println("Fib(16) : " + Fibonacci(16));
  }

  public static int Fibonacci(int x) {
    if (x <= 1) return 1;
    else return Fibonacci(x - 1) + Fibonacci(x - 2);
  }
}
