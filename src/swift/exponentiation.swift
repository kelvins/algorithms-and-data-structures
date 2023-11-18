func exponentiation<Number: Numeric>(base: Number, power: Int) -> Number {
    var result = base
    if power == 0 {
        return 1
    }
    for _ in 0..<power - 1 {
        result *= base
    }
    return result
}

func main() {
    print(exponentiation(base: 5, power: 3))
    print(exponentiation(base: 2.5, power: 4))
    print(exponentiation(base: 50, power: 0))
}

main()
