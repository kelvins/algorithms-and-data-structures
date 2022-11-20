
def calculatePi(n: Int): Double = {
  (0 until n).foldLeft(0.0)((pi, index) => {
    val operation: Double = if (index % 2 == 0) 1.0 else -1.0
    val denominator: Double = 1.0 + (index * 2.0)
    pi + (operation * (4.0 / denominator))
  })
}

object Main extends App {
  val nTerms: Seq[Int] = Seq(10, 1000, 100000, 10000000)
  nTerms.foreach(n => println(s"Pi ($n): ${calculatePi(n)}"))
}
