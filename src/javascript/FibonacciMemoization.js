const fibonacci = (function () {
  const memo = {};

  function fib(n) {
    if (n <= 1) {
      return n;
    }

    if (memo[n] !== undefined) {
      return memo[n];
    }

    memo[n] = fib(n - 1) + fib(n - 2);

    return memo[n];
  }

  return fib;
})();

function main() {
  console.log('Fibonacci (memoization) of 30:', fibonacci(30));
}

main();

