fn main() {
    let array = vec![54, 42, 11, 33, 24, 99, 77, 80];
    min_max(array, i32::MAX, i32::MIN, 0);
}

fn min_max(array: Vec<i32>, mut min: i32, mut max: i32, index: usize) {
    if array[index] < min {
        min = array[index];
    }
    if array[index] > max {
        max = array[index];
    }
    if index < array.len() - 1 {
        min_max(array, min, max, index + 1);
    } else {
        println! {"Data: {:?}", array};
        println! {"Min.: {:?}", min};
        println! {"Max.: {:?}", max};
    }
}
