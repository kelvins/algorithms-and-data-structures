
package hanoi

import "fmt"

func Hanoi(pino0 int, pino2 int, pino1 int, numero int) {
    if numero == 1 {
        fmt.Println("Mover de ", pino0, " para ", pino2)
    } else {
        Hanoi(pino0, pino1, pino2, numero-1)
        Hanoi(pino0, pino2, pino1, 1)
        Hanoi(pino1, pino2, pino0, numero-1)
    }
}
