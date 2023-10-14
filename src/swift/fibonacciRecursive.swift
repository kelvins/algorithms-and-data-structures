// Function to calculate Fibonacci numbers recursively
func fibonacciRecursive(_ number: Int) -> Int {
    if number <= 1 {
        return number
    } else {
        // Recursively calculate Fibonacci using the formula F(n) = F(n-1) + F(n-2)
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2)
    }
}

let index: Int = 15
print("Fibonacci (recursive):", fibonacciRecursive(index))
