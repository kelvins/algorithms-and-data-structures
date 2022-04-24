import util.control.Breaks._

def search(data: List[Int], value: Int): Int = {
  var index: Int = -1
  breakable {
    for (i <- 0 to data.length - 1) {
      if (data(i) == value) {
        index = i
        break
      }
    }
  }
  index
}

object Main extends App {
  val data: List[Int] = List(9, 2, 6, 1, 3, 5, 4, 7, 8)
  println(data)

  val values: List[Int] = List(9, 3, 8, 246)
  for (value <- values) {
    val index = search(data, value)
    if (index >= 0) {
      println(s"Value $value found -> index $index")
    } else {
      println(s"Value $value not found!")
    }
  }
}
