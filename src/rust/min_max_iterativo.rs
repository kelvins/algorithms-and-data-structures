fn main() {
    min_max(vec![54,42,11,33,24,99,77,80]);
}

fn min_max(vetor: Vec<i32>) {
    let mut min = vetor[0];
    let mut max = vetor[0];

    for i in 1..vetor.len() {
        if vetor[i] < min {
            min = vetor[i];
        } else if vetor[i] > max {
            max = vetor[i];
        }
    }

    println!{"Data: {:?}", vetor};
    println!{"Min.: {:?}", min};
    println!{"Max.: {:?}", max};
}
