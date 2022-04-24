
def minMax(data: List[Int], minimum: Int, maximum: Int, index: Int): (Int, Int) = {
  var min: Int = minimum
  var max: Int = maximum

  if (data(index) < min) {
    min = data(index)
  }
  if (data(index) > max) {
    max = data(index)
  }

  if (index < data.length - 1) {
    minMax(data, min, max, index + 1)
  } else {
    (min, max)
  }
}

def minMax(data: List[Int]): (Int, Int) = minMax(data, data(0), data(0), 0)

object Main extends App {
  val data: List[Int] = List(4, 6, 2, 9, 3, 8, 1, 7, 5)
  val (min, max) = minMax(data)
  println(s"$data\nMin: $min\nMax: $max")
}
