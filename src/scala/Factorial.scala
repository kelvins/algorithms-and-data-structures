def factorial(n: Long): Long = (1L to n).product

object Main extends App {
  val data: Map[Long, Long] = Map(
    0L  -> 1L,
    1L  -> 1L,
    5L  -> 120L,
    20L -> 2432902008176640000L
  )
  data.foreach { (key, value) =>
    val result: Long = factorial(key)
    assert(result == value)
    println(s"Factorial($key): $result")
  }
}
