fn torre_hanoi(pin0: i32, pin2: i32, pin1: i32, num: i32){
  if num == 1{
    println!("Move from {} to {}", pin0, pin2)
  }else{
    torre_hanoi(pin0, pin1, pin2, num - 1);
    torre_hanoi(pin0, pin2, pin1, 1);
    torre_hanoi(pin1, pin2, pin0, num - 1);
  }
}
fn main(){
  torre_hanoi(0,2,1,3);
}