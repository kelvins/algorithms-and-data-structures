fn fibonacci(number: i32) -> i32{
    if number < 2 {
      return number;
    }else{
      return fibonacci(number - 1) + fibonacci(number - 2);
    }
  }
fn main() {
  println!("{:?}", fibonacci(3));        
  println!("{:?}", fibonacci(15));   
  println!("{:?}", fibonacci(30)); 
}
