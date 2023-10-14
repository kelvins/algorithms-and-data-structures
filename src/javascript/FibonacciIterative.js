function fibonacci(n) {
  if (n <= 1) {
    return n;
  }

  let a = 0;
  let b = 1;
  let result;

  for (let i = 2; i <= n; i++) {
    result = a + b;
    a = b;
    b = result;
  }

  return result;
}

function main() {
  console.log('Fibonacci (iterative) of 30:', fibonacci(30));
}

main();
