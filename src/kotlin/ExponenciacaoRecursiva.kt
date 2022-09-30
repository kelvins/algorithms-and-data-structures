/**
 * Função "exponenciacaoRecursiva"
 * 
 * A função *exponenciacaoRecursiva* apresenta os valores de um número(*base*) elevado por um *expoente*.
 * Nessa função, usa -se o conceito da *recursividade*, na qual, a função criada é chamada dentro dela, 
 * uma ou mais vezes internamente da mesma.
 * 
 * @author Versão do algoritmo para Kotlin: Alfredo Paes <alfredo.alfpaes@gmail.com>
 * @see https://github.com/Alfredo-Paes
 * 
 * @param base é do tipo inteiro(Int)
 * @param expoente é do tipo inteiro(Int) 
 * 
 * @return retornará o número *base* elevado pelo *expoente*. A função retorna um valor do tipo *Long*.
 */
fun exponenciacaoRecursiva(base: Int, expoente: Int): Long {
  return if (expoente === 0) 1;
  else base * exponenciacaoRecursiva(base, expoente - 1);
}

fun main() {
 println(exponenciacaoRecursiva(2, 3));
}