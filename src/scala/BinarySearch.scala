import scala.annotation.tailrec

def binarySearch(data: Seq[Int], target: Int): Option[Int] = {

  @tailrec
  def search(left: Int, right: Int): Option[Int] = {
    if (left > right) None
    else {
      val middle: Int = (left + right) / 2
      if (data(middle) == target) Some(middle)
      else if (data(middle) < target) search(middle + 1, right)
      else search(left, middle - 1)
    }
  }
  search(0, data.size)
}

object Main extends App {
  val data: Seq[Int] = Seq(0, 1, 3, 5, 6, 7, 8, 9, 10, 11, 12)
  val value: Int = 11
  println(
    s"Value '$value' found in position '${binarySearch(data, value).get}'"
  )
}
