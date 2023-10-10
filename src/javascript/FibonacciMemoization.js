/**
 * A memoização é uma abordagem que podemos usar para escrever a função fibonacci. Resumindo é uma técnica de otimização em que amarzenamos os valores de resultados anteriores, de modo semelhante a um cache.
 *
 * @param {number} n 
 */
function fibonacciMemoization(n) {
  const memo = [0, 1]; 
  const fibonacci = (n) => {
    if(memo[n] != null) return memo[n];
    return memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
  };

  return fibonacci;
}