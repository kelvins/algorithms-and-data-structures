/**
 * Função "fibonacciRecursiva"
 * 
 * A função *FibonacciRecursiva* apresenta os valores da sequência de Fibonacci em que,
 * os primeiros dois termos dessa sequência são menor ou igual 1, e cada termo que vier
 * a seguir será a soma dos dois números anteriores (0, 1, 1, 2, 3, 5, 8...).
 * Nessa função, usa -se o conceito da *recursividade*, na qual, a função criada é chamada
 * dentro dela, uma ou mais vezes internamente da mesma.
 * 
 * @author Versão do algoritmo para Kotlin: Alfredo Paes <alfredo.alfpaes@gmail.com>
 * @see https://github.com/Alfredo-Paes
 * 
 * @param number é do tipo inteiro(Int)
 * 
 * @return retornará uma condição lógica se *number* for menor ou igual a 1, retorna 1 se não, 
 * o somatório dela mesma utilizando o conceito de *recursividade* para a execução deste somatório.
 */
fun fibonacciRecursivo(number: Int): Int {
    return if (number <= 1) 1;
    else fibonacciRecursivo(number-1) + fibonacciRecursivo(number-2);
};

fun main(){
    println(fibonacciRecursivo(5));
};