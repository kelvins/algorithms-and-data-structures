fn main(){
  println!("{:?}", calculate_pi(vec![10, 1000, 100000, 10000000]));
}
fn calculate_pi(terms: Vec<i32>) -> Vec<f64> {
  let mut denominator: f64;
  let mut operation: f64;
  let mut pi: Vec<f64> = Vec::<f64>::new();

  for i in 0..terms.len() {
    denominator = 1.0;
    operation = 1.0;
    pi.push(0.0);
    for _ in 0..terms[i] {
      let i: usize = i as usize;
      pi[i] += operation * (4.0 / denominator);
      denominator += 2.0;
      operation *= -1.0;
    }
  }
  pi
}