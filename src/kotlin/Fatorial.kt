/**
 * Função "fatorial"
 *
 * A função *Fatorial* apresenta os valores da multiplicação *n números* por seus antecessores maiores ou iguais a 1.
 *
 * @author Versão do algoritmo para Kotlin: Alfredo Paes <alfredo.alfpaes@gmail.com>
 * @see https://github.com/Alfredo-Paes
 *
 * @param numero é do tipo inteiro(Int)
 *
 * @return retornará um número do tipo *Long* no qual o tipo está atribuido para a variável *fatorial*.
 */

fun fatorial(numero: Int) {
    val numeroInicial: Int = numero
    var fatorial: Long = 1

    for (i in 1..numeroInicial) {
        fatorial *= i.toLong()
    }

    println("Fatorial de $numero! é $fatorial")
}

fun main() {
    fatorial(7)
}
