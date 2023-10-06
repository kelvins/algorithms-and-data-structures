import scala.annotation.tailrec

object Main extends App {
  
  @tailrec
  def search(data: List[Int], value: Int): Int = {
    if(data.headOption == Some(value)) {
      value
    } else if(data.size == 1 && value != data.head) {
      -1
    } else {
      search(data.drop(1), value)
    }  
  }

  val data: List[Int] = List(9, 2, 6, 1, 3, 5, 4, 7, 8)
  val values: List[Int] = List(9, 3, 8, 246)
  val searchResults: List[Int] = values.map(v => search(data, v))
  println(searchResults)
  
}
