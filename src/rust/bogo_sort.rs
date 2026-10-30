/*
    Contributors
        - Dromedario de Chapéu

    Bogo sort is a joke algorithm and one of the slowest sorting algorithms.
    It repeatedly shuffles the list and checks whether it is sorted. Since
    the order is random, sorting may take over a million attempts or finish
    on the first try.
*/

// To use this library, create a Cargo project
// and add rand as a dependency.
use rand::prelude::*;

fn is_sorted(list: Vec<u8>) -> bool {
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
    let mut cycles: u64 = 0;
    loop {
        cycles += 1;
        list.shuffle(&mut rng);
        if is_sorted(list.clone()) {
            return (list, cycles);
        }
    }
}

// The u8 type for list items is used only to
// generate large numbers that are harder to inspect.
fn generate_list(len: u8) -> Vec<u8> {
    let mut rng = thread_rng();
    let mut list = Vec::<u8>::new();
    for _ in 0..len - 1 {
        list.push(rng.gen());
    }
    return list;
}

fn main() {
    let list_unordered = generate_list(6);
    print!("Unsorted list: ");
    for i in list_unordered.iter() {
        print!("{i} ")
    }
    println!();

    let (list, cycles) = bogo_sort(list_unordered);
    println!("Sorting took {cycles} attempts");
    print!("Sorted list: ");
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
    fn sorting() {
        let mut unordered = generate_list(6);
        let (sorted, _) = bogo_sort(unordered.clone());
        unordered.sort();
        assert_eq!(sorted, unordered);

        let unordered = vec![6, 5, 4, 3, 2, 1];
        let (sorted, _) = bogo_sort(unordered);
        assert_eq!(sorted, vec![1, 2, 3, 4, 5, 6]);
    }
}
