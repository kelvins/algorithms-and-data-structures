object FibonacciIterative {
  def fibonacci(n: Int): BigInt = {
    if (n <= 1) {
      return n
    }

    var a = BigInt(0)
    var b = BigInt(1)
    var result = BigInt(0)

    for (i <- 2 to n) {
      result = a + b
      a = b
      b = result
    }

    result
  }

  def main(args: Array[String]): Unit = {
    val index = 15
    println(s"Fibonacci (iterative) of $index is: ${fibonacci(index)}")
  }
}
