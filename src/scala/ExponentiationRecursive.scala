import scala.annotation.tailrec

@tailrec
def exponentiationRecursive(base: Int, exponent: Int, accumulator: Int = 1): Int = exponent match {
  case 0 => accumulator
  case _ => exponentiationRecursive(base, exponent - 1, accumulator * base)
}

object Main extends App {
  println("5 ^ 3 = " + exponentiationRecursive(5, 3))
}
