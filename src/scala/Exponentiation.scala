def exponentiation(base: Int, exponent: Int): Int = {
  (1 to exponent)
    .map(_ => base)
    .reduce(_ * _)
}
    
object Main extends App {
  println("5 ^ 3 = " + exponentiation(5, 3))
}