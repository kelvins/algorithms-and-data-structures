fn main() {
    min_max(vec![54, 42, 11, 33, 24, 99, 77, 80]);
}

fn min_max(array: Vec<i32>) {
    let mut min = array[0];
    let mut max = array[0];

    for i in 1..array.len() {
        if array[i] < min {
            min = array[i];
        } else if array[i] > max {
            max = array[i];
        }
    }

    println! {"Data: {:?}", array};
    println! {"Min.: {:?}", min};
    println! {"Max.: {:?}", max};
}
