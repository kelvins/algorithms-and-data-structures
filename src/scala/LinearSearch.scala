def search(data: List[Int], value: Int): Int = {
  data.zipWithIndex
    .find((tupleValue, _) => tupleValue == value)
    .map((_, index) => index)
    .getOrElse(-1)
}

object Main extends App {
  val data: List[Int]    = List(9, 2, 6, 1, 3, 5, 4, 7, 8)
  val values: List[Int]  = List(9, 3, 8, 246)
  val results: List[Int] = values.map(v => search(data, v))

  values
    .zip(results)
    .foreach((value, result) => println(s"Value: $value -> Index: $result"))
}
