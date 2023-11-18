func factorial(_ number: Int) -> Int {
    var result: Int = 1
    for index in (1...number).reversed() {
        result = result * index
    }
    return result
}

print(factorial(5))

