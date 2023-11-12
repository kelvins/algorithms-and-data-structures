// Note that this is just for study purposes since Scala provides a built-in Queue collection:
// https://www.scala-lang.org/api/current/scala/collection/mutable/Queue.html

import scala.collection.mutable.ListBuffer

class Queue[Any] {
  private var queue: ListBuffer[Any] = ListBuffer()

  def enqueue(value: Any): Unit = queue += value

  def dequeue(): Any = queue.remove(0)

  override def toString(): String = queue.mkString(", ")
}

object Main extends App {
  val queue = new Queue[Int]

  println("Queuing 3 values...")
  queue.enqueue(1)
  queue.enqueue(2)
  queue.enqueue(3)
  println(queue)

  println("Dequeuing 1 value...")
  queue.dequeue()
  println(queue)
}
