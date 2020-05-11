
package fibonacci

func Fibonacci(value int) (int) {
    if value <= 1 {
        return 1
    } else {
        return Fibonacci(value-1) + Fibonacci(value-2)
    }
}
