fn main() {
    let vetor = vec![54,42,11,33,24,99,77,80];
    min_max(vetor, i32::MAX, i32::MIN, 0);
}

fn min_max(vetor: Vec<i32>, mut min: i32, mut max: i32, indice: usize) {
    if vetor[indice] < min {
        min = vetor[indice];
    }
    if vetor[indice] > max {
        max = vetor[indice];
    }
    if indice < vetor.len() - 1 {
        min_max(vetor, min, max, indice + 1);
    } else {
        println!{"Data: {:?}", vetor};
        println!{"Min.: {:?}", min};
        println!{"Max.: {:?}", max};
    }
}
