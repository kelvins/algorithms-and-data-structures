
def minMax(data: List[Int]): (Int, Int) = {
  var min: Int = data(0)
  var max: Int = data(0)
  for (value <- data) {
    if (value < min) {
      min = value
    }
    if (value > max) {
      max = value
    }
  }
  (min, max)
}

object Main extends App {
  val data: List[Int] = List(4, 6, 2, 9, 3, 8, 1, 7, 5)
  val (min, max) = minMax(data)
  println(s"$data\nMin: $min\nMax: $max")
}
