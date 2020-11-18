fn main(){
  println!("{:?}", fatorial_recursiva(3));
  println!("{:?}", fatorial_recursiva(4));
  println!("{:?}", fatorial_recursiva(5));
  println!("{:?}", fatorial_recursiva(10));
}

fn fatorial_recursiva(number: i32) -> i32 {
  if number <= 1 {
    return 1;
  }
  number * fatorial_recursiva(number - 1)
}