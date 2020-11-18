fn main(){
  println!{"3^3 = {:?}", exponentiation_recursive(3,3)}
  println!{"3^4 = {:?}", exponentiation_recursive(3,4)}
  println!{"2^3 = {:?}", exponentiation_recursive(2,3)}
  println!{"5^2 = {:?}", exponentiation_recursive(5,2)}
}

fn exponentiation_recursive(base: i32, exponent: i32) -> i32{
  if exponent <= 1 {
    return base;
  }
  base * exponentiation_recursive(base, exponent - 1)
}