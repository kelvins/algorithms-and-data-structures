// Function to calculate Fibonacci numbers iteratively
func fibonacci(_ number: Int) -> Int {
    if number <= 1 {
        return number
    } else {
        var currentNumber: Int = 1
        var nextNumber: Int = 0

        // Iterate from 0 to 'number - 1'
        for _ in 0..<number {
            let tempNumber = nextNumber
            nextNumber = nextNumber + currentNumber
            currentNumber = tempNumber
        }

        return currentNumber
    }
}

let index: Int = 15
print("Fibonacci (iterative):", fibonacci(index))
