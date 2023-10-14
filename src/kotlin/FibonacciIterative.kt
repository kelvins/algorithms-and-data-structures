// Function to calculate Fibonacci numbers iteratively
fun fibonacciIterative(n: Int): Long {
    if (n <= 1) {
        return n.toLong()
    }

    var a = 0L
    var b = 1L
    var result = 0L

    for (i in 2..n) {
        result = a + b
        a = b
        b = result
    }

    return result
}

fun main() {
    val index = 15
    println("Fibonacci (iterative) of $index is: ${fibonacciIterative(index)}")
}
