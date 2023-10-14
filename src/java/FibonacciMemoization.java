import java.util.HashMap;

public class Fibonacci {

  // Create a memoization HashMap to store computed Fibonacci values
  private static HashMap<Integer, Integer> memo = new HashMap<>();

  public static void main(String[] args) {
    int n = 16;
    System.out.println("Fib(" + n + ") : " + fibonacci(n));
  }

  public static int fibonacci(int n) {
    if (n <= 1) {
      return 1;
    }

    // Check if the value is already computed and stored in the memoization HashMap
    if (memo.containsKey(n)) {
      return memo.get(n);
    }

    // Calculate Fibonacci recursively and store the result in memoization
    int result = fibonacci(n - 1) + fibonacci(n - 2);
    memo.put(n, result);

    return result;
  }
}
