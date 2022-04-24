// Note that this is just for study purposes since Scala provides a built-in Stack collection:
// https://www.scala-lang.org/api/current/scala/collection/mutable/Stack.html

import scala.collection.mutable.ListBuffer

class Stack[Any] {
  private var stack: ListBuffer[Any] = ListBuffer()

  def push(value: Any): Unit = stack += value

  def pop(): Any = stack.remove(stack.length - 1)

  override def toString(): String = stack.mkString(", ")
}

object Main extends App {
  val stack = new Stack[Int]

  println("Pushing 3 values...")
  stack.push(1)
  stack.push(2)
  stack.push(3)
  println(stack)

  println("Poping 1 value...")
  stack.pop()
  println(stack)
}
