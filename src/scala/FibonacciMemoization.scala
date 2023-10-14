object FibonacciMemoization {
  import scala.collection.mutable.Map

  val memo: Map[Int, BigInt] = Map()

  def fibonacciMemoization(n: Int): BigInt = {
    if (n <= 1) {
      return n
    }

    memo.getOrElseUpdate(n, fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2))
  }

  def main(args: Array[String]): Unit = {
    val index = 15
    println(s"Fibonacci (memoization) of $index is: ${fibonacciMemoization(index)}")
  }
}
