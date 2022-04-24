
def bubble_sort(data: List[Int]): List[Int] = {
  var sortedData: List[Int] = data
  var swapped: Boolean = true
  while (swapped == true) {
    swapped = false
    for (i <- 0 to sortedData.length - 2) {
      if (sortedData(i) > sortedData(i+1)) {
        sortedData = sortedData.updated(i, sortedData(i+1)).updated(i+1, sortedData(i))
        swapped = true
      }
    }
  }
  sortedData
}

object Main extends App {
  var data: List[Int] = List(9, 2, 8, 1, 5, 7, 3, 6, 4)
  println(data)
  var sortedData: List[Int] = bubble_sort(data)
  println(sortedData)
}
