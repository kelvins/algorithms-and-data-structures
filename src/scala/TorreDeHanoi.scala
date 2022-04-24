
def hanoi(pin0: Int, pin2: Int, pin1: Int, disks: Int): Unit = {
  if (disks == 1) {
    println(s"Move de $pin0 para $pin2")
  } else {
    hanoi(pin0, pin1, pin2, disks - 1)
    hanoi(pin0, pin2, pin1, 1)
    hanoi(pin1, pin2, pin0, disks - 1)
  }
}

object Main extends App {
  hanoi(0, 2, 1, 3)
}
