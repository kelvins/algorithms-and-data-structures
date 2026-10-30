/*
    Contributors
        - Dromedario de Chapéu

    Linear search is a simple but inefficient algorithm. It checks each item
    until it finds the target or reaches the end of the slice.

    It works with unsorted data and is useful for small collections. For large
    collections, its linear runtime can become a bottleneck.
*/
fn linear_search(slice: &[i32], value: i32) -> (bool, usize) {
    for (i, c) in slice.iter().enumerate() {
        if *c == value {
            return (true, i);
        }
    }
    return (false, 0);
}

fn main() {
    let slice = vec![1, 2, 3, 4];
    let (exists, index) = linear_search(&slice, 2);
    println!("{}, {}", exists, index);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn search() {
        let slice = vec![1, 2, 3, 4];
        assert_eq!(linear_search(&slice, 2), (true, 1));
        assert_eq!(linear_search(&slice, 0), (false, 0));
    }
}
