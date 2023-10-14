// Memoization dictionary to store computed Fibonacci numbers
var memo: [Int: Int] = [:]

// Function to calculate Fibonacci numbers using memoization
func fibonacci(_ n: Int) -> Int {
    if n <= 1 {
        return n
    }

    // Check if the result is already memoized
    if let cachedResult = memo[n] {
        return cachedResult
    }

    // Calculate Fibonacci recursively and store the result in memoization
    let result = fibonacci(n - 1) + fibonacci(n - 2)
    memo[n] = result

    return result
}

let index: Int = 15
print("Fibonacci (memoization):", fibonacci(index))
