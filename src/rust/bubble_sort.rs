fn bubble_sort(mut slice: Vec<i32>) -> Vec<i32> {
  for i in 0..slice.len() {
    for j in 0..slice.len() - 1 - i {
      if slice[j] > slice[j + 1] {
        slice.swap(j, j + 1);
      }
    }
  }
  slice
}
fn main(){
  println!("{:?}", bubble_sort(vec![4, 65, 2, -31, 0, 99, 2, 83, 782, 1]));
}
