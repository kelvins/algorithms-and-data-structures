public class FibonacciRecursive {

  public static void main(String[] args) {
    System.out.println("Fib(16) : " + FibonacciRecursive(16));
  }

  public static int FibonacciRecursive(int x) {
    if (x <= 1) return 1;
    else return FibonacciRecursive(x - 1) + FibonacciRecursive(x - 2);
  }
}
