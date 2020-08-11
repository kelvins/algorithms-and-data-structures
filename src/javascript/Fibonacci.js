/**
 * 
 * @param {number} n 
 */
function fibonacci(n) {
  return n < 2 ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

function main(){
  console.log('fibonacci 30 -> ', fibonacci(30))
}

main();