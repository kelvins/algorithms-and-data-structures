object FibonacciRecursive {
  def fibonacci(n: Int): BigInt = {
    if (n <= 1) {
      return n
    }

    fibonacci(n - 1) + fibonacci(n - 2)
  }

  def main(args: Array[String]): Unit = {
    val index = 15
    println(s"Fibonacci (recursive) of $index is: ${fibonacci(index)}")
  }
}
