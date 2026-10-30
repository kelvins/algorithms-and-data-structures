fn main() {
    println! {"{:?}", insertion_sort(vec![54,42,11,33,24,99,77,80])};
}
fn insertion_sort(mut array: Vec<i32>) -> Vec<i32> {
    for i in 1..array.len() {
        let mut index: i32 = i as i32;
        while index > 0 && array[index as usize] < array[index as usize - 1] {
            array.swap(index as usize, index as usize - 1);
            index -= 1;
        }
    }
    array
}
