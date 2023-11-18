/* recursiveExponentiation.swift
Written by Roberto Martins on 10/10/2023
*/

func recursiveExponentiation<Number: Numeric>(base: Number, power: Int) -> Number {
    if (power == 0) {
        return 1
    }
    return base * recursiveExponentiation(base: base, power: power - 1)
}

func main() {
    print(recursiveExponentiation(base: 5, power: 3))
    print(recursiveExponentiation(base: 2.5, power: 4))
    print(recursiveExponentiation(base: 50, power: 0))
}

main()