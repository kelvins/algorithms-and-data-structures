// Function to calculate Fibonacci numbers recursively
func fibonacci(_ number: Int) -> Int {
    if number <= 1 {
        return number
    } else {
        // Recursively calculate Fibonacci using the formula F(n) = F(n-1) + F(n-2)
        return fibonacci(number - 1) + fibonacci(number - 2)
    }
}

let index: Int = 15
print("Fibonacci (recursive):", fibonacci(index))
