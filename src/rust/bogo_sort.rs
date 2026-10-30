/*
    Contribuidores
        - Dromedario de Chapéu

    O Bogo Sort é um algoritmo feito apenas como uma piada, sendo
    o pior e mais demorado algoritmo de sortção. Tudo o que ele faz
    é pegar uma list, randomizar os seus itens, e check se todos
    os itens estão ordenados. Logo, ele é 100% aleatório, o que pode
    fazer com que demore mais de 1 milhão de tentativas até ser sorted,
    ou que simplesmente na first tentativa ele seja sorted.

*/

// To use this library, create a Cargo project
// and add rand as a dependency.
use rand::prelude::*;

fn check_ordem(list: Vec<u8>) -> bool {
    for index in 0..list.len() - 1 {
        if list[index] > list[index + 1] {
            return false;
        }
    }
    return true;
}

// Vec<u8> means that the "list" parameter is a list of
// 8-bit unsigned integers. The u64 return value refers
// to the number of cycles needed to sort the list.
fn bogo_sort(mut list: Vec<u8>) -> (Vec<u8>, u64) {
    let mut rng = thread_rng();
    // A large limit was chosen because bogo sort
    // can be either the fastest or slowest algorithm,
    // so a large range helps prevent the program from crashing.
    let mut ciclos: u64 = 0;
    loop {
        ciclos += 1;
        list.shuffle(&mut rng);
        if check_ordem(list.clone()) {
            return (list, ciclos);
        }
    }
}

// The u8 type for list items is used only to
// generate large numbers that are harder to inspect.
fn gera_list(len: u8) -> Vec<u8> {
    let mut rng = thread_rng();
    let mut list = Vec::<u8>::new();
    for _ in 0..len - 1 {
        list.push(rng.gen());
    }
    return list;
}

fn main() {
    let list_unordered = gera_list(6);
    print!("List unordered: ");
    for i in list_unordered.iter() {
        print!("{i} ")
    }
    println!();

    let (list, ciclos) = bogo_sort(list_unordered);
    println!("Foram necesarios um total de {ciclos} para sort");
    print!("List sorted: ");
    for i in list.iter() {
        print!("{i} ");
    }
    println!();
}

// Unit tests
#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn oredenacao() {
        let mut unordered = gera_list(6);
        let (sorted, _) = bogo_sort(unordered.clone());
        unordered.sort();
        assert_eq!(sorted, unordered);

        let unordered = vec![6, 5, 4, 3, 2, 1];
        let (sorted, _) = bogo_sort(unordered);
        assert_eq!(sorted, vec![1, 2, 3, 4, 5, 6]);
    }
}
