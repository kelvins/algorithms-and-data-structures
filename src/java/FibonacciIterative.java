public class Fibonacci {

  public static void main(String[] args) {
    System.out.println("Fib(16) : " + Fibonacci(16));
  }

  public static int Fibonacci(int x) {
    if (x <= 1) {
      return 1;
    } else {
      int n = 1, nextValue = 1;
      for (int i = 0; i < x - 1; i++) {
        int temp = nextValue;
        nextValue = nextValue + n;
        n = temp;
      }
      return n;
    }
  }
}
