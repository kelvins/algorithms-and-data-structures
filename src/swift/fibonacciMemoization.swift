// Memoization dictionary to store computed Fibonacci numbers
var memo: [Int: Int] = [:]

// Function to calculate Fibonacci numbers using memoization
func fibonacciMemoization(_ n: Int) -> Int {
    if n <= 1 {
        return n
    }

    // Check if the result is already memoized
    if let cachedResult = memo[n] {
        return cachedResult
    }

    // Calculate Fibonacci recursively and store the result in memoization
    let result = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2)
    memo[n] = result

    return result
}

let index: Int = 15
print("Fibonacci (memoization):", fibonacciMemoization(index))
