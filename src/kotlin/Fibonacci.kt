/**
 * "fibonacciRecursive" function
 *
 * The *fibonacciRecursive* function displays the values of the Fibonacci sequence in which, the first two terms of this sequence are less than or equal to 1, and each term that follows next will be the sum of the two previous numbers (0, 1, 1, 2, 3, 5, 8...).
 * In this function, the concept of *recursion* is used, in which the created function is called within it, one or more times internally.
 *
 *
 * @param number is of type integer (Int)
 *
 * @return will return a logical condition if *number* is less than or equal to 1, returns 1 otherwise, the sum of itself using the concept of *recursion* to execute this sum.
 */
fun fibonacciRecursive(number: Int): Int {
    return if (number <= 1) {
        1
    }; else {
        fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2)
    }
}

fun main() {
    println(fibonacciRecursive(5))
}
