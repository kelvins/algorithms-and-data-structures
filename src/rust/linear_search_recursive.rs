/*
    Contributors
        - Dromedário de Chapéu

    Recursive linear search follows the same approach as iterative linear
    search, but uses repeated function calls instead of a loop. Each call
    checks the next item until it finds the target or reaches the end.

    Recursion uses additional memory and processing, so this approach can be
    costly for large slices.
*/

// The only change from the regular linear search declaration is the added parameter
// index, which indicates the current position in the list.
fn linear_search_recursive(list: &[i32], value: i32, index: usize) -> (bool, usize) {
    // The first if checks whether recursion has advanced far enough
    // for the index to reach the end of the list; all items have then
    // been checked.
    if index == list.len() {
        return (false, 0);
    } else if list[index] == value {
        return (true, index);
    }

    // If the current item is not the target, call the function again with the index
    // incremented so the next call checks the next
    // item in the list.
    return linear_search_recursive(list, value, index + 1);
}

fn main() {
    let list = vec![1, 2, 3, 4];
    let (exists, index) = linear_search_recursive(&list, 0, 0);
    println!("{}, {}", exists, index);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn search() {
        let list = vec![1, 2, 3, 4];
        assert_eq!(linear_search_recursive(&list, 2, 0), (true, 1));
        assert_eq!(linear_search_recursive(&list, 0, 0), (false, 0));
    }
}
