/**
 * "exponentiationRecursive" function
 *
 * The *exponentiationRecursive* function presents the values of a number (*base*) raised by an *exponent*.
 * In this function, the concept of *recursion* is used, in which the created function is called within it, one or more times internally of the same.
 *
 * @param base is of type integer (Int)
 * @param exponent is of type integer (Int)
 *
 * @return will return the *base* number raised by the *exponent*. The function returns a value of type *Long*.
 */
fun exponentiationRecursive(base: Int, exponent: Int): Long {
    return if (exponent == 0) {
        1
    }; else {
        base * exponentiationRecursive(base, exponent - 1)
    }
}

fun main() {
    println(exponentiationRecursive(2, 3))
}
