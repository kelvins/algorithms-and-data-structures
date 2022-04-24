
def recursiveMax(data: List[Int], max: Int, index: Int): Int = {
  var maximum = max
  if (data(index) > max) {
    maximum = data(index)
  }
  if (index < data.length - 1) {
    maximum = recursiveMax(data, maximum, index + 1)
  }
  maximum
}

def recursiveMax(data: List[Int]): Int = recursiveMax(data, data(0), 0)

object Main extends App {
  val data: List[Int] = List(1, 5, 2, 7, 3, 9, 4, 6)
  val max = recursiveMax(data)
  println(s"$data\nMax: $max")
}
