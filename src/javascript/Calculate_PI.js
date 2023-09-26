function calculate_pi(number) {
  let denominator = 1;
  let operation = 1;
  let pi = 0;

  for (let cont = 0; cont < number; cont++) {
    pi += operation * (4 / denominator);
    denominator += 2;
    operation *= -1;
  }

  return pi;
}

function main() {
  const terms = [10, 1000, 100000, 10000000];
  terms.map((term) => {
    console.log(`PI ${term}: ${calculate_pi(term)}`);
  });
}

main();
