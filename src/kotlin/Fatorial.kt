/**
 * "factorial" function
 *
 * The *factorial* function presents the values of multiplying *n numbers* by their predecessors greater than or equal to 1.
 *
 * @author Algorithm version for Kotlin: Alfredo Paes <alfredo.alfpaes@gmail.com>
 * @see https://github.com/Alfredo-Paes
 *
 * @param number is of type integer (Int)
 *
 * @return will return a number of type *Long* in which the type is assigned to the *factorial* variable.
 */

fun factorial(number: Int) {
    val initialNumber: Int = number
    var factorial: Long = 1

    for (i in 1..initialNumber) {
        factorial *= i.toLong()
    }

    println("Factorial of $number! is $factorial")
}

fun main() {
    factorial(7)
}
