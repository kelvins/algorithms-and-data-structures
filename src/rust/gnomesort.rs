fn main(){
  println!("{:?}", gnomesort(vec![1,3,5,2]));
}
fn gnomesort(mut slice: Vec<i32>) -> Vec<i32> {
  let mut pivot: i32 = 0;
  let size: i32 = slice.len() as i32;

  while pivot < size - 1 {
    if slice[pivot as usize] > slice[pivot as usize + 1] {
      let temp: i32 = slice[pivot as usize];
      slice[pivot as usize] = slice[pivot as usize + 1];
      slice[pivot as usize + 1] = temp;
      if pivot > 0 {
        pivot -= 2;
      }
    }
    pivot += 1;
  }
  slice
}