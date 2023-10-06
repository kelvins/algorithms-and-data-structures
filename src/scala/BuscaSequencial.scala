object Main extends App {

  def search(data: List[Int], value: Int): Int = {
    data.zipWithIndex.find(tuple => {
      val (tupleValue, _) = tuple
      tupleValue == value
    }).map(tuple => {
      val (_, index) = tuple
      index
    }).getOrElse(-1)  
  }
	
  val data: List[Int] = List(9, 2, 6, 1, 3, 5, 4, 7, 8)
  val values: List[Int] = List(9, 3, 8, 246)
  val searchResults: List[Int] = values.map(v => search(data, v))
  println(searchResults)
}
