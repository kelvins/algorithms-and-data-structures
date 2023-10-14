object FibonacciRecursive {
  def fibonacciRecursive(n: Int): BigInt = {
    if (n <= 1) {
      return n
    }

    fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2)
  }

  def main(args: Array[String]): Unit = {
    val index = 15
    println(s"Fibonacci (recursive) of $index is: ${fibonacciRecursive(index)}")
  }
}
