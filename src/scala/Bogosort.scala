import scala.annotation.tailrec
import scala.util.Random

@tailrec
def isSorted(data: Seq[Int]): Boolean = {
  if (data.size < 2) true
  else if (data(0) > data(1)) false
  else isSorted(data.tail)
}

@tailrec
def bogosort(data: Seq[Int]): Seq[Int] = {
  val result: Seq[Int] = Random.shuffle(data)
  if (isSorted(result)) result
  else bogosort(data)
}

object Main extends App {
  val data: Seq[Int] = Seq.fill(10)(Random.nextInt(10))
  println(s"Unsorted data: $data")
  println(s"Sorted data: ${bogosort(data)}")
}

